#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <filesystem> // C++17

namespace fs = std::filesystem;

bool is_image_file(const fs::path& path) {
    std::string ext = path.extension().string();
    for (auto& c : ext) c = tolower(c); // Make lowercase
    return ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".bmp" || ext == ".tiff";
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "Usage: ./image_viewer <folder_path>" << std::endl;
        return -1;
    }

    std::string folder_path = argv[1];
    std::vector<std::string> image_paths;

    // Collect all image files
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (entry.is_regular_file() && is_image_file(entry.path())) {
            image_paths.push_back(entry.path().string());
        }
    }

    if (image_paths.empty()) {
        std::cerr << "No image files found in folder: " << folder_path << std::endl;
        return -1;
    }

    size_t current_index = 0;
    const std::string window_name = "Image Viewer";

    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    while (true) {
        cv::Mat img = cv::imread(image_paths[current_index]);
        if (img.empty()) {
            std::cerr << "Failed to load image: " << image_paths[current_index] << std::endl;
            break;
        }

        cv::imshow(window_name, img);

        int key = cv::waitKey(0);

        if (key == 27) { // ESC key
            break;
        }
        else if (key == 81 || key == 'a') { // Left arrow or 'a'
            if (current_index > 0) current_index--;
        }
        else if (key == 83 || key == 'd') { // Right arrow or 'd'
            if (current_index < image_paths.size() - 1) current_index++;
        }
    }

    cv::destroyAllWindows();
    return 0;
}
