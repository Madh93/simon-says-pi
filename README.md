# simon-says-pi

Simon game for Raspberry Pi based on Qt 4.

<p align="center">
<video autoplay="" controls="" loop="" class="video-js vjs-default-skin col-lg-12" data-setup="{}">
  <source src="https://zippy.gfycat.com/ForthrightImmaterialEstuarinecrocodile.webm" type="video/webm">
</video>
</p>

Tested on Raspberry Pi 1 Model B + [Adafruit PiTFT - 320x240 2.8" Touchscreen](https://www.adafruit.com/product/1601).

### Requirements

- Qt 4 (tested on 4.8.4 and 4.8.7)
- Phonon

To install requirements in Ubuntu (16.04) and derivatives:

    sudo apt install qt4-default qt4-qmake qt4-dev-tools qt4-qmlviewer libqt4-dev-bin libqt4-opengl libqt4-opengl-dev libphonon-dev

To install requirements in Arch and derivatives:

    sudo pacman -S qt4 phonon-qt4

Optional but **recommended** to deploy on Raspberry Pi: [Qt Creator](https://www.qt.io/download-open-source/).

### Installation

Assuming Raspberry Pi and Qt Creator are already configured for cross compilation:

Open `simon-says-pi.pro` in Qt Creator IDE: build and run.

Or using terminal to run only on x86 host:

    git clone https://github.com/Madh93/simon-says-pi && cd simon-says-pi
    qmake
    make

And run:

    cd simon-says-pi/build/release
    ./simon-says-pi

### Deploying server

Game statistics are sent to a server where are stored in a MongoDB database using a RESTful API written in Go. The statistics can be visualizated in a browser dashboard written in Python with Dash library.

    cd simon-says-pi/server
    docker-compose up

Don't forget to edit configuration file (`config/application.ini`) with correct `api/host` and `api/port` values.
