#include "data_handler.hpp"

data_handler::data_handler()
{
    data_array = new std::vector<data *>;
    training_data = new std::vector<data *>;
    testing_data = new std::vector<data *>;
    validation_data = new std::vector<data *>;
}

// nb ~ indicates a destructor
data_handler::~data_handler()
{
    delete data_array;
    delete training_data;
    delete testing_data;
    delete validation_data;
}

void data_handler::read_feature_vector(std::string file_path)
{
    uint32_t header[4]; // |MAGIC |NUM IMAGES |ROWSIZE |COLSIZE|
    unsigned char bytes[4];
    FILE *f = fopen(file_path.c_str(), "rb"); // Changed to binary read mode
    if (f)
    {
        for (int i = 0; i < 4; i++)
        {
            if (fread(bytes, sizeof(bytes), 1, f)) // Read all 4 bytes at once
            {
                header[i] = convert_to_lil_endian(bytes);
            }
        }
        printf("Done reading header.\n");
        // printf("Magic number: %d\n", header[0]);
        // printf("Number of images: %d\n", header[1]);
        // printf("Rows: %d\n", header[2]);
        // printf("Cols: %d\n", header[3]);

        int image_size = header[2] * header[3];
        feature_vector_size = image_size;
        printf("Image size: %d\n", image_size);

        for (int i = 0; i < header[1]; i++)
        {
            data *d = new data();
            uint8_t element[1];
            for (int j = 0; j < image_size; j++)
            {
                if (fread(element, sizeof(element), 1, f))
                {
                    d->append_to_feature_vector(element[0]);
                }
                else
                {
                    printf("Error reading image data at image %d, pixel %d\n", i, j);
                    exit(1);
                }
            }
            data_array->push_back(d);
        }
        printf("Successfully stored %lu feature vectors\n", data_array->size());
    }
    else
    {
        printf("Could not find file: %s\n", file_path.c_str());
        exit(1);
    }
    fclose(f);
}
void data_handler::read_feature_labels(std::string file_path)
{
    uint32_t header[2]; // |MAGIC |NUM IMAGES|
    unsigned char bytes[4];
    FILE *f = fopen(file_path.c_str(), "rb"); // Changed to binary read mode
    if (f)
    {
        for (int i = 0; i < 2; i++)
        {
            if (fread(bytes, sizeof(bytes), 1, f)) // Read all 4 bytes at once
            {
                header[i] = convert_to_lil_endian(bytes);
            }
        }
        printf("Done reading label header.\n");
        // printf("Magic number: %d\n", header[0]);
        // printf("Number of labels: %d\n", header[1]);

        for (int i = 0; i < header[1]; i++)
        {
            uint8_t element[1];
            if (fread(element, sizeof(element), 1, f))
            {
                data_array->at(i)->set_label(element[0]);
            }
            else
            {
                printf("Error reading label at position %d\n", i);
                exit(1);
            }
        }
        printf("Successfully stored %d labels\n", header[1]);
    }
    else
    {
        printf("Could not find file: %s\n", file_path.c_str());
        exit(1);
    }
    fclose(f);
}

void data_handler::split_data()
{
    std::unordered_set<int> used_indices;
    int training_size = data_array->size() * TRAINING_DATA_RATIO;
    int testing_size = data_array->size() * TESTING_DATA_RATIO;
    int validation_size = data_array->size() * VALIDATION_DATA_RATIO;

    // training data
    int count = 0;
    while (count < training_size)
    {
        int index = rand() % data_array->size();
        if (used_indices.find(index) == used_indices.end())
        {
            training_data->push_back(data_array->at(index));
            used_indices.insert(index);
            count++;
        }
    }

    // testing data
    count = 0;
    while (count < testing_size)
    {
        int index = rand() % data_array->size();
        if (used_indices.find(index) == used_indices.end())
        {
            testing_data->push_back(data_array->at(index));
            used_indices.insert(index);
            count++;
        }
    }

    // validation data
    count = 0;
    while (count < validation_size)
    {
        int index = rand() % data_array->size();
        if (used_indices.find(index) == used_indices.end())
        {
            validation_data->push_back(data_array->at(index));
            used_indices.insert(index);
            count++;
        }
    }

    printf("Split data into training, testing, and validation sets\n");
    printf("Training size: %lu\n", training_data->size());
    printf("Testing size: %lu\n", testing_data->size());
    printf("Validation size: %lu\n", validation_data->size());
}

void data_handler::count_classes()
{
    int count = 0;
    for (unsigned i = 0; i < data_array->size(); i++)
    {
        if (class_map.find(data_array->at(i)->get_label()) == class_map.end())
        {
            class_map[data_array->at(i)->get_label()] = count;
            data_array->at(i)->set_enum_label(count);
            count++;
        }
    }
    num_classes = count;
    printf("Successfully counted %d unique classes\n", num_classes);
}

uint32_t data_handler::convert_to_lil_endian(const unsigned char *bytes)
{
    return (uint32_t)((bytes[0] << 24) |
                      (bytes[1] << 16) |
                      (bytes[2] << 8) |
                      (bytes[3]));
}

std::vector<data *> *data_handler::get_training_data()
{
    return training_data;
}
std::vector<data *> *data_handler::get_testing_data()
{
    return testing_data;
}
std::vector<data *> *data_handler::get_validation_data()
{
    return validation_data;
}

// int main()
// {
//     data_handler *dh = new data_handler();
//     dh->read_feature_vector("./mnist_data/train-images-idx3-ubyte");
//     dh->read_feature_labels("./mnist_data/train-labels-idx1-ubyte");
//     dh->count_classes();
//     dh->split_data();

//     return 0;
// }
