----
<!---
\begin{bmatrix}
 &  &  & \\
 &  &  & \\
 &  &  & \\
 &  &  &
\end{bmatrix} 

<p style="text-align: center;">A piece of centered text</p>

<img

style="display: block;
-->
# Why study transformation?
- modeling
- viewing
----
# 2D Transformations
## Homogeneous Coordinates
- ***why need this?***
Transformations using 2\*2 matrix are hard to be unified. like:
$$
\begin{bmatrix}
x' \\
y'
\end{bmatrix} =
\begin{bmatrix}
a & b\\
c & d
\end{bmatrix} 
\begin{bmatrix}
x \\
y
\end{bmatrix} +
\begin{bmatrix}
t_x \\
t_y
\end{bmatrix} 
$$
- ***definition?***
Add an extra coordinate $w$: $(x,y,w)^T$
- 2D-vector = $(x, y, 0)^T$
- 2D-point = $(x,y,1)^T$.
$$
\begin{bmatrix}
x'\\
y'\\
1
\end{bmatrix} =
\begin{bmatrix}
a & b & t_x\\
c & d & t_y\\
0 & 0 & 1
\end{bmatrix}
\begin{bmatrix}
x \\
y \\
1
\end{bmatrix} 
$$
>**NOTE: for 2D-point, $(x,y,w)^T=(\frac{x}{w},\frac{y}{w},1)^T\hspace{1cm}w\neq 0$.**
## Linear Transformations
operated on 2D-vectors.
### scaling matrix
$$S(s_x,s_y)=
\begin{bmatrix}
s_x & 0 & 0 \\
0 & s_y & 0 \\
0 & 0 & 1
\end{bmatrix}
$$
$s_x$, $s_y$ are scaling factor in its axis respectively.
### reflection matrix
$$
\begin{bmatrix}
-1 & 0 & 0\\
0 & 1 & 0 \\
0 & 0 & 1
\end{bmatrix} 
$$
![[reflection matrix.png|400]]
*x-axis reflection*
### shear matrix
$$
\begin{bmatrix}
1 & a & 0\\
0 & 1 & 0\\
0 & 0 & 1
\end{bmatrix}
$$
![[shear_2d.png|400]]
- horizontal shift is $ay$
- vertical not changed
### rotate matrix
$$R(\theta)=
\begin{bmatrix}
cos\theta & -sin\theta & 0 \\
sin\theta & cos\theta & 0\\
0 & 0 & 1
\end{bmatrix} 
$$
*rotating $\theta$ degrees*
![[rotate_2d.png|400]]
## Translation Matrix
operated on 2D-point.
$$T(t_x,t_y)=
\begin{bmatrix}
1 & 0 & t_x\\
0 & 1 & t_y\\
0 & 0 & 1
\end{bmatrix} 
$$

----
# Inverse and Compose Transforms

define **linear transformation matrix** $M$ (using homogeneous coordinates):
$$M=
\begin{bmatrix}
a & b & t_x\\
c & d & t_y\\
0 & 0 & 1
\end{bmatrix} 
$$
## Inverse Transform
$M^{-1}$ is the inverse transform matrix.
## Composing Transforms
1. Matrix multiplication is **not commutative**, also the transformations.
2. Matrices are applied **from right to left**.
$$A_n(...A_2(A_1(x)))=A_n...A_2 \cdot A_1x=Mx$$
***Decomposing Transformation?***
1. Translate to the origin.
2. Rotate the angle you want.
3. Translate back.
![[composing_transforms.png|700]]
$$M=T(c)\cdot R(\alpha) \cdot T(-c)$$