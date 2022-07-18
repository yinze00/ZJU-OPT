# CH2：球面与球面系统

[toc]

---

### 1. 基本概念

- 子午平面
- 弧矢平面
- 光轴
- 物方截距、像方截距
- 物方倾斜角、像方倾斜角

### 2. 符号规则

<img src = "res\ch2_f1.png" style="zoom: 50%;" />

- 沿轴线段

  ==以顶点为基准，左负右正==

- 垂轴线段

  ==以光轴为基准，上正下负==

- 角度

  ==顺正逆负== 

  ==角度优先级：法线 > 光线 > 光轴== **优先级高的边在判断角度时不动**



### 3. 折射球面

- 近轴光学（高斯光学）

  ==完善成像==   $\Large tani \approx sini \approx i$

- 共轭点

  ==一对物像点==

<img src = "res\ch2_f2.png" style="zoom: 70%;" />

- ==阿贝不变量 Q==
  $$
  \Large n(\frac{1}{r}-\frac{1}{l})=n'(\frac{1}{r}-\frac{1}{l'})=Q
  $$

- :star:==物像关系==
  $$
  \Large \frac{n'}{l'}-\frac{n}{l}=\frac{n'-n}{r}
  $$

- ==角度关系==
  $$
  \Large n'u'-nu=\frac{n’-n}{r}h
  $$

- ==重要的公式==

  $\Large h=lu=l'u'$

- 光焦度

  $\Large \phi = \frac{n'-n}{r}$  用于表征折射球面光学特性的物理量 ==正/负 --> 会聚/发散==

- 像方焦点、物方焦点

- :star:==像方焦距、物方焦距==  
  $$
  \Large f'=\frac{n'}{n'-n}r \\
  \Large f=-\frac{n}{n'-n}r \\
  \Large f'+f=r \\
  \Large \frac{f'}{l'}+\frac{f}{l}=1 \\
  \Large \phi = \frac{n'}{f'}=-\frac{n}{f} \\
  \Large \frac{f'}{n'}=-\frac{f}{n}
  $$
  `最后两个公式适用于任何光学系统`

- :star: ==放大率==

  - 横向放大率（垂轴放大率）
    $$
    \Large \beta = \frac{y'}{y}=\frac{nl'}{n'l}=\frac{nu}{n'u'}
    $$

  - 轴向放大率
    $$
    \Large \alpha = \frac{nl'^{2}}{n'l^{2}}=\frac{n'}{n} \beta^{2}
    $$

  - 角度放大率
    $$
    \Large \gamma = \frac{u'}{u}=\frac{l}{l'}=\frac{n}{n'}·\frac{1}{\beta}
    $$
    ==三种放大率的关系==
    $$
    \Large \beta=\alpha \gamma
    $$

- 拉赫不变量
  $$
  \Large J=nyu=n'y'u'
  $$

  
  
  ​	拉赫不变量表征了`光学系统的性能`，数值越大，成像的范围越大，成像的孔径角越大，传输的光能越多。

### 4. 反射球面

​	==$n'=-n$==

- 凸面镜、凹面镜

​	<img src = "res\ch2_f3.png" style="zoom: 80%;" />



- 物像公式
  $$
  \Large \frac{1}{l'}+\frac{1}{l}=\frac{2}{r}
  $$

- 焦距
  $$
  \Large f'=f=\frac{r}{2}
  $$

- 放大率
  $$
  \Large \beta = -\frac{l'}{l} \\
  \Large \alpha = -\beta^{2} \\
  \Large \gamma = -\frac{1}{\beta^{2}}
  $$

- 拉赫不变量
  $$
  \Large J=nyu=-ny’u'
  $$