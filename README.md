<div align="center">
  <a href="https://github.com/alkynee/sensors-hyper">
    <img src="https://drive.google.com/uc?export=view&id=1UAFr3tepqKwdnTomhKaeI2eIag3HOISY" alt="" style="width: 150px;">
  </a>

<h2><em>Hyper</em>Sensors</h2>
  <p>
    Implementations of common sensing modalities for computer vision. 
    <br />
    <a href="https://github.com/alkynee/sensors-hyper/issues">Report Issues or Request Features</a>
  </p>
</div>
<br />

## About

[*Hyper*Sensors](https://github.com/alkynee/sensors-hyper) are part of the 
[*Hyper*SLAM](https://github.com/alkynee/hyperSensors) framework and implement, based on 
the [*Hyper*Variables](https://github.com/alkynee/hyperVariables) repository, the physical sensor models (i.e. 
absolute sensor, pinhole camera and inertial measurement unit models) employed 
in *Hyper*SLAM. If you use this repository, please cite it as below.

```
@article{RAL2022Hug,
    author={Hug, David and B\"anninger, Philipp and Alzugaray, Ignacio and Chli, Margarita},
    journal={IEEE Robotics and Automation Letters},
    title={Continuous-Time Stereo-Inertial Odometry},
    year={2022},
    volume={7},
    number={3},
    pages={6455-6462},
    doi={10.1109/LRA.2022.3173705}
}
```
***Note:*** Development on HyperSLAM-related repositories has been discontinued.

## Installation

[*Hyper*Sensors](https://github.com/alkynee/sensors-hyper) depends on the 
[*Hyper*Variables](https://github.com/alkynee/hyperVariables) and 
[*Hyper*State](https://github.com/alkynee/hyperState) libraries and uses features from the 
[C++20](https://en.cppreference.com/w/cpp/20) standard (see 
[link](https://askubuntu.com/questions/26498/how-to-choose-the-default-gcc-and-g-version) to update gcc and g++ 
alternatives). All dependencies aside from the ones contained in the `setup.sh` script are automatically fetched 
during compilation. The compilation process itself (without additional compile flags) is as follows:

```
# Clone repository.
git clone https://github.com/alkynee/sensors-hyper.git && cd sensors-hyper/

# Run setup.
chmod +x setup.sh
sudo setup.sh

# Build repository.
mkdir build && cd build
cmake ..
make
```

## Literature

1. [Continuous-