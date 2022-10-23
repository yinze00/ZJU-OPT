

# CH6: 光能于传播

[toc]

---

### 1. 基本概念

- 辐射能通量
- `光通量（流明 $\large lm$）`
- 光谱光视效率
- 发光效率
- `发光强度（坎德拉 $\large cd$）`
- `光照度（勒克斯 $\large lx$）`
- 光出射度（勒克斯 $\large lx$）
- 反射率
- 白体、黑体
- 光亮度（尼特 $\large nt$）
- 朗伯光源
- 吸收率
- `像面照度（勒克斯 $\large lx$）`
- `相对孔径`

### 2. 光通量 $\large \varPhi$

​	==可见光范围：$\large 400 - 760 \  nm$，人眼对 $\large 555 \ nm$ 的黄光最敏感==

​	==相同功率的不同单色光所相当的光通量不同==

- 光谱光视效率：

$$
\large V_{\lambda}=\frac{K_{\lambda}}{K_{555}}
$$

- 发光效率
  $$
  \large \eta = \frac{\varPhi}{W}
  $$

### 3. 光度学基础

- 立体角
  $$
  \large d\varOmega=\frac{dS}{R^{2}}=sin\varphi d\varphi d\theta
  $$

- 发光强度 
  $$
  \large I=\frac{d \varPhi}{d \omega} \\
  \large d \omega = sini·di·d\varphi
  $$
  ==锥体的发光强度==

  <img src="./res/ch6_f1.png" style="zoom: 60%;" align="middle"/>

  
  $$
  \large \varPhi = 4 \pi I_{0} sin^{2}\frac{U}{2}
  $$
  ==各向同性光源==
  $$
  \large \varPhi = 4 \pi I_{0}
  $$
  
- ==光照度==

  ==表征受照面被照明的亮暗程度==

  <img src="./res/ch6_f2.png" style="zoom: 70%;" align="middle"/>
  $$
  \large E=\frac{\Phi}{S} \\
  \large E=\frac{I·cosi}{R^{2}}
  $$

- 光出射度

  ==表征面光源的发光特性==
  $$
  \large M=\frac{d\Phi}{dS} \\
  \large M=\frac{\Phi}{S}
  $$
  ==二次光源==
  $$
  \large M=\rho E
  $$
  白体：反射率接近 1 

  黑体：反射率接近 0 

- ==光亮度==

  ==表征人眼对发光体或被照射物体表面的发光或反射光强度感受的物理量==

  <img src="./res/ch6_f3.png" style="zoom: 70%;" align="middle"/>
  $$
  \large L_{i}=\frac{d \Phi}{cosi·dS·d \omega}=\frac{I}{cosi·dS}=\frac{I}{dS_{N}}
  $$
  朗伯光源（余弦辐射体）

  $\large L$ 不随方向变化，光强分布如下：
  $$
  \large I_{i}=L \times S \times cosi
  $$
  <img src="./res/ch6_f4.png" style="zoom: 70%;" align="middle"/>

### 4. 光的传播

- `反射光路`
  $$
  \large L''=\rho L
  $$

- `折射光路`
  $$
  \large L'=(1-\rho)L(\frac{n'}{n})^{2}
  $$

- 光能损失

  <img src="./res/ch6_f5.png" style="zoom: 70%;" align="middle"/>

  

  透过率为 $\large \tau$ ，空气中为 1
  $$
  \large L=L_{0} \tau^{d}
  $$

- 

- :star:`像面照度`

  <img src="./res/ch6_f6.png" style="zoom: 90%;" align="middle"/>

  $\large K$ 是透过率
  $$
  \large E'=\frac{\varPhi'}{dS'}=\frac{1}{\beta^{2}} \pi K L sin^{2}U \\
  \large \beta =\frac{nsinU}{n'sinU'} \\
  $$

  ##### 摄影系统的照度

  ==入瞳直径 $\large 2a$，相对孔径 $\large D={2a}/{f'}$，入瞳到出瞳的放大倍率 $\large \beta_{p}$（一般为 1）==
  $$
  \large E=\frac{\pi KL}{4}(\frac{2a}{f'})^{2}·\frac{\beta_{p}^{2}}{(\beta_{p}-\beta)^{2}}
  $$

  ##### 轴外点在像面轴上点的照度

  $$
  \large E_{M}'=E'cos^{4}W' \\
  \large E'=\frac{1}{\beta^{2}}\pi K Lsin^{2}U
  $$

  ##### 照度总结

  $$
  \large E' \propto sin^{2}U \\
  \large E' \propto \frac{1}{\beta^{2}}
  $$

  