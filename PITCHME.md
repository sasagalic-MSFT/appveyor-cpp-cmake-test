# Recurrent Neural Networks

<!---
## Math rendering

### Rendering via www.sciweavers.org (Not working)

* ![a_h^t = \sum_{i=1}^I w_{ih}x_i^t + \sum_{h'=1}^H w_{h'h}b_{h'}^{t-1}](http://www.sciweavers.org/tex2img.php?eq=%20a_h%5Et%20%3D%20%5Csum_%7Bi%3D1%7D%5EI%20w_%7Bih%7Dx_i%5Et%20%2B%20%5Csum_%7Bh%27%3D1%7D%5EH%20w_%7Bh%27h%7Db_%7Bh%27%7D%5E%7Bt-1%7D%20&bc=White&fc=Black&im=jpg&fs=12&ff=mathdesign&edit=0)

* ![a_h^t](http://www.sciweavers.org/tex2img.php?eq=a_h%5Et&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0) - input to hidden unit h at time t
* ![b_h^t](http://www.sciweavers.org/tex2img.php?eq=b_h%5Et&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0) − output of hidden unit h at time t

### HTML math (poor rendering quality, only simple equations)

 h<sub>&theta;</sub>(x) = &theta;<sub>o</sub> x + &theta;<sub>1</sub>x

### Rendering via latex.codecogs.com

![equation](https://latex.codecogs.com/svg.latex?\Large&space;x=\frac{-b\pm\sqrt{b^2-4ac}}{2a})
--->

## Introduction

* Sequence labeling – process of transcribing data sequence to sequence of discrete labels
* Applications
  * Speech recognition
  * Handwriting recognition
  * Protein secondary structure prediction
* Sequence labeling vs. pattern classification
  * Correlations in input data and output data ![importance of context](context.png)

## Problem types

* Pattern classification

  ![pattern classification](pattern_classification.png) -> T

* Sequence classification

  ![sequence classification](sequence_classification.png) -> T

* Segment classification

  ![segment classification](segment_classification.png)
  * Frame-wise labels
  * Context
  * Time windows

* Temporal classification

  ![temporal classification](temporal_classification.png) -> Text
  * Unsegmented labels

## Unfolding RNN

* Unfolding network along input sequence
* No recurrent connections

  ![unfolding](unfolded_rnn.png)

## Recurrent Neural Network (RNN)

* MLP maps input vector to output vector
* Recurrent connections allow ‘memory’ of previous inputs
* RNN maps entire history of previous inputs to output vector
  ![rnn](rnn.png)

## Forward pass

* Almost the same as MLP, except inputs come from the hidden layer as well

  * input to hidden unit `h` at time `t`

    <!--- a_h^t = \sum_{i=1}^I w_{ih}x_i^t + \sum_{h'=1}^H w_{h'h} b_{h'}^{t-1} --->
    ![a_h^t](https://latex.codecogs.com/svg.latex?a_h%5Et%20%3D%20%5Csum_%7Bi%3D1%7D%5EI%20w_%7Bih%7Dx_i%5Et%20&plus;%20%5Csum_%7Bh%27%3D1%7D%5EH%20w_%7Bh%27h%7D%20b_%7Bh%27%7D%5E%7Bt-1%7D)

  * output of hidden unit `h` at time `t`

    <!--- a_h^t = \sum_{i=1}^I w_{ih}x_i^t + \sum_{h'=1}^H w_{h'h} b_{h'}^{t-1} --->
    ![b_h^t](https://latex.codecogs.com/svg.latex?b_h%5Et%20%3D%20%5Ctheta_h%28a_h%5Et%29)

  ![forward pass](forward.png)

## Backward pass

* Backpropagation through time (BPTT)

  <!--- \delta_h^t = \theta'(a_h^t) \left ( \sum_{k=1}^K w_{hk} \delta_k^t + \sum_{h'=1}^H w_{hh'} \delta_{h'}^{t+1} \right ) --->
  ![\delta_h^t](https://latex.codecogs.com/svg.latex?%5Cdelta_h%5Et%20%3D%20%5Ctheta%27%28a_h%5Et%29%20%5Cleft%20%28%20%5Csum_%7Bk%3D1%7D%5EK%20w_%7Bhk%7D%20%5Cdelta_k%5Et%20&plus;%20%5Csum_%7Bh%27%3D1%7D%5EH%20w_%7Bhh%27%7D%20%5Cdelta_%7Bh%27%7D%5E%7Bt&plus;1%7D%20%5Cright%20%29)

  <!--- \frac{\partial L}{\partial w_{ij}} = \sum_{t=1}^T \frac{\partial L}{\partial a_j^t} \frac{\partial a_j^t}{\partial w_{ij}} = \sum_{t=1}^T \delta_j^t b_i^t --->
  ![grad](https://latex.codecogs.com/svg.latex?%5Cfrac%7B%5Cpartial%20L%7D%7B%5Cpartial%20w_%7Bij%7D%7D%20%3D%20%5Csum_%7Bt%3D1%7D%5ET%20%5Cfrac%7B%5Cpartial%20L%7D%7B%5Cpartial%20a_j%5Et%7D%20%5Cfrac%7B%5Cpartial%20a_j%5Et%7D%7B%5Cpartial%20w_%7Bij%7D%7D%20%3D%20%5Csum_%7Bt%3D1%7D%5ET%20%5Cdelta_j%5Et%20b_i%5Et)

  ![backward pass](forward.png)
