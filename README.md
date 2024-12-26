# Configuration Steps for Cookbook OCR (C++ Project with Crow)

Follow these steps to configure the Cookbook OCR project on a WSL Linux local machine:

1. **Install dependencies and setup Crow**
  ```sh
  sudo apt-get update
  sudo apt install cmake libtesseract-dev tesseract-ocr libcurl4-openssl-dev libasio-dev
  git clone https://github.com/CrowCpp/Crow.git
  cd Crow
  mkdir build
  cd build
  cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF
  make
  sudo make install
  ```

2. **Run service locally**
  ```sh
  cd Crow cookbook_ocr
  mkdir build
  cd build
  cmake ..
  make
  ./CookbookOCR
  ```