#include "ocr_handler.h"
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>

std::string processImage(const std::string& imagePath) {
    tesseract::TessBaseAPI api;
    if (api.Init(nullptr, "eng")) { // Use English language model
        throw std::runtime_error("Could not initialize tesseract.");
    }

    Pix* image = pixRead(imagePath.c_str());
    if (!image) {
        throw std::runtime_error("Could not read image file.");
    }

    api.SetImage(image);
    std::string text = api.GetUTF8Text();

    pixDestroy(&image);
    api.End();

    return text;
}
