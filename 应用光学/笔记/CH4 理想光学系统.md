# CH4: 理想光学系统

[toc]

---

### 1. 基础概念

- `理想光学系统` ==（对任意宽空间内的点以任意宽的光束成完善像的光学系统）==

- 共轭点

- 共轭直线

- 共轭光束

- 共轭平面

- 透镜的曲率半径 $\large r_{1},\ r_{2}$

- 透镜的通光孔径 $\large D$

- 焦平面（垂轴平面）

- `焦距` ==（主点到对应焦点的距离，以主点为原点确定正负）==
  $$
  \large f'=\frac{h}{tanu'} \\
  \large f =\frac{h}{tanu} (f<0) \\
  \large \frac{f'}{f}=-\frac{n'}{n}
  $$

- `焦点`==（不共轭）==

- `主平面`（垂轴平面，虚构的平面）

- `主点` ==（共轭，$\large \beta = 1$）==

- `节点` ==（共轭，$\large \gamma =1$）==

<img src = "res\ch4_f1.png" style="zoom: 80%;" />

### 2. 物像关系

- 焦物距 $\large x$，焦像距 $\large x'$ ==(以焦点为原点确定正负)== 

- `牛顿公式`
  $$
  \large xx'=ff' \\
  \large \beta=\frac{y'}{y}=-\frac{x'}{f'}=-\frac{f}{x}
  $$

- 物距 $\large l$，像距 $\large l'$ ==（以主点为原点确定正负）==
  $$
  \large l=x+f \\
  \large l'=x'+f'
  $$

- `高斯公式`
  $$
  \large \frac{f'}{l'}+\frac{f}{l}=1 \\
  \large \frac{n'}{l'}-\frac{n}{l}=\frac{n'}{f'}=-\frac{n}{f}
  $$

- :star:`介质相同`
  $$
  \large n=n' \\
  \large f=-f' \\
  \large \frac{1}{l'}-\frac{1}{l}=\frac{1}{f'} \\
  \large \beta = \frac{l'}{l} \\
  \large l = (\frac{1}{\beta}-1)f' \\
  \large l'=(1-\beta)f'
  $$

- 共轭距 $\large L$
  $$
  \large L=l'-'+HH'=(2-\beta-\frac{1}{\beta})f'+HH'
  $$

- `拉赫不变量`
  $$
  \large nytanU=n'y'tanU'
  $$
  <img src = "res\ch4_f2.png" style="zoom: 90%;" />

- `光焦度` $\large \varPhi$
  $$
  \large V=\frac{n}{l} \\
  \large V'=\frac{n'}{l'} \\
  \large \varPhi = V'-V \\
  \large \varPhi = \frac{n'}{f'}=-\frac{n}{f}
  $$
  ==光焦度是像方光束会聚度与物方光束会聚度之差==

  ==正值 -- 会聚作用 / 负值 -- 发散作用==

- 屈光度

  ==以米为单位的焦距的倒数==

  ==眼镜度数=屈光度数 × 100==

- `成像规律`

  - 正/倒：取决于 $\large \beta$ 的正负
  - 虚/实：取决于物的虚实
  - 放大/缩小：取决于 $\large \left| \beta \right|>1$ ？

### 3. 作图方法

- :star:`作图原则`

  - 平行入射的光线，经过像方焦点出射

  - 经过物方焦点的光线，平行出射

  - 过节点的光线，平行出射

  - 平行入射的光线，会聚于像方焦面的一点出射

  - 物方焦面的一点入射的光线，平行出射

  - 光线与物方、像方主面的交点，高度相等

    [作图题练习](./4.5Ans.pdf) 建议再画一遍

### 4. 光学系统的组合

​	<img src = "res\ch4_f3.png" style="zoom: 80%;" />



- 光学间隔 $\large \varDelta$
- 透镜的间隔 $\large d$
- `共轭关系`
  - $\large F \& F2 $
  - $\large F' \& F_{1}'$

- :star:`组合系统的基点`
  $$
  \large x_{F}'=-\frac{f_{2}f_{2}'}{\varDelta} \\
  \large x_{F}=\frac{f_{1}f_{1}'}{\varDelta} \\
  \large l_{F}'=f_{2}'+x_{F}' \\
  \large l_{F}=f_{1}+x_{F} \\
  \large x_{H}'=x_{F}'-f' \\
  \large x_{H}=x_{F}-f \\
  \large l_{H}'=f_{2}'+x_{H}' \\
  \large l_{H}=f_{1}+x_{H} \\
  \large \varDelta = d-f_{1}'+f_{2} \\
  $$

- :star:`组合系统的光焦度`
  $$
  \large \phi = \phi_{1}+\phi_{2}-d\phi_{1}\phi_{2}
  $$

- :star:`组合系统的焦距`
  $$
  \large f'=\frac{f_{1}'f_{2}'}{f_{1}'+f_{2}'-d} \\
  \large f'=-\frac{f_{1}'f_{2}'}{\varDelta} \\
  \large f=\frac{f_{1}f_{2}}{\varDelta}
  $$
  <img src = "res\ch4_f4.png" style="zoom: 80%;" />

- :star:`焦距测量`

  

- `多光组组合`

  - 正切计算法

  $$
  \large l_{F}'=\frac{h_{k}}{u_{k}'} \\
  \large f'=\frac{h_{1}}{u_{k}'} \\
  \large l_{H}'=l_{F}'-f' \\
  \large h=ltanU=l'tanU'=lu=l'u' \\
  \large u'-u=\frac{h}{f'}
  $$

  - 截距计算法

- 复杂光学系统的总光焦度
  $$
  \large \phi=\frac{1}{h_{1}} \sum{h_{\phi}}
  $$
  ==当透镜位于像面或中间实像面上时，总光焦度的贡献为 0==

- `镜头`

  - 远摄镜头

    ==主面前移，长焦距，工作距离短==

    <img src = "res\ch4_f5.png" style="zoom: 90%;" />

  - 广角镜头

    ==主面后移，短焦距，工作距离长==

    <img src = "res\ch4_f6.png" style="zoom: 90%;" />

### 5. 望远镜系统

​	该部分将放在 [chapter 12](CH12 典型光学系统.md) 具体讲述

### 6. 透镜

- 薄透镜定义

- 凸透镜、凹透镜 $\large d \ ? D$

  ==凸透镜， $\large f' > 0$ ，正光焦度，实焦点，会聚作用==

  ==凹透镜， $\large f' < 0$ ，负光焦度，虚焦点，发散作用==

- `薄透镜的焦距公式`
  $$
  \large f'=\frac{1}{(n-1)(\frac{1}{r_{1}}-\frac{1}{r_{2}})} \\
  \large \phi = \frac{1}{f'}
  $$

- 厚透镜

  - 双凸透镜

  - 双凹透镜（光焦度 < 0）

  - `平凸透镜`
    $$
    \large f'=-f=\frac{r_{1}}{n-1} \\
    \large l_{H}'=-\frac{d}{n} \\
    \large l_{H}=0
    $$

  - 平凹透镜

    ==焦距一直为负值，且与厚度无关==

  - 总结

    - 正+正组合
    - 负+负组合
    - 正+负组合

### 7. 焦距测量

- :star: `平行光管`
  $$
  \large y'=-f'tanU'=-f'tanW
  $$
  
  
  
- :star: `折射球面`
  $$
  \large y'=-(f'-r)tanW
  $$