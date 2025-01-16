# k-Nearest Neighbors Algorithm

Given a query point $x_q$ and training set $T = \{(x_i, y_i)\}_{i=1}^n$:

## Distance Metrics

For any point $x_i$:
```math
d(x_q, x_i) = \begin{cases}
    \sqrt{\sum_{j=1}^m (x_{qj} - x_{ij})^2} & \text{Euclidean} \\
    \sum_{j=1}^m |x_{qj} - x_{ij}| & \text{Manhattan} \\
    \left(\sum_{j=1}^m |x_{qj} - x_{ij}|^p\right)^{1/p} & \text{Minkowski}
\end{cases}
```

## Classification
For discrete class labels $y_i$:
```math
\hat{y} = \underset{c}{\operatorname{argmax}} \sum_{i \in N_k(x_q)} \mathbb{I}(y_i = c)
```
where:
- $N_k(x_q)$ is the set of k nearest neighbors to $x_q$
- $\mathbb{I}$ is the indicator function
- $c$ is a class label

## Regression
For continuous values $y_i$:

### 1. Uniform weights
```math
\hat{y} = \frac{1}{k} \sum_{i \in N_k(x_q)} y_i
```

### 2. Distance-weighted
```math
\hat{y} = \frac{\sum_{i \in N_k(x_q)} w_i y_i}{\sum_{i \in N_k(x_q)} w_i}
```
where weights $w_i = \frac{1}{d(x_q, x_i)^2}$ give more importance to closer neighbors.
