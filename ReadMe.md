
# Tiny VIO


Please ignore for now.
A weekend project to create a smallest visual-inertial estimator.



### Dependencies
Tested on Ubuntu 20.04 LTS on WLS2
```
sudo apt install git cmake g++
sudo apt install libeigen3-dev libopencv-dev
```

We use [Pangolin](https://github.com/stevenlovegrove/Pangolin) to do visualization.
Might need to follow this guide if on WSL https://woojjang.tistory.com/52
```
git clone https://github.com/stevenlovegrove/Pangolin
cd Pangolin
git submodule update --init
./scripts/install_prerequisites.sh recommended
mkdir build && cd build
cmake ..
make
echo LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/<path_here>/Pangolin/build/ # add to bashrc
export XDG_RUNTIME_DIR=/tmp/xdg
export RUNLEVEL=3
```


### Goals

- Read in [EuRoC MAV](https://projects.asl.ethz.ch/datasets/doku.php?id=kmavvisualinertialdatasets) inertial and image data.
- State: [R, p, v, bg, ba, g, pf...pf] (6dof unobserable)
- Initialize features directly in the state vector as SLAM features with infinite depths



