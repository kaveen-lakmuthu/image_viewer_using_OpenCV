# Image Viewer using OpenCV and C++

Just a small image viewer made for practicing C++ programming.

<img src="./Screenshot_20250405_130745.png" alt="Screenshot of the image viewer.">

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/kaveen-lakmuthu/image_viewer_using_OpenCV.git
   ```

2. Create a build directory and compile the program:
   ```bash
   cd image_viewer_using_OpenCV
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the program:
   ```bash
   ./image_viewer ../path/to/your/folder_with_images/
   ```
   or, to open a single image:
   ```bash
   ./image_viewer ../path/to/your/image.jpg
   ```

## Usage

This image viewer is capable of:

- Opening a **single image** or **multiple images** from a folder.
- Navigating between images:
  - Press **`A`** or **Left Arrow (←)** to go to the previous image.
  - Press **`D`** or **Right Arrow (→)** to go to the next image.
- Press **`ESC`** key to exit the viewer at any time.

The window automatically resizes to match the dimensions of the current image. Simple keyboard controls make it easy to browse through multiple photos!

## Requirements

- C++17 or higher
- OpenCV 4.x
- CMake 3.10 or higher

Install OpenCV (if not already installed):

```bash
sudo apt update
sudo apt install libopencv-dev
```

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

---