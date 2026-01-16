#include <iostream>
#include <fstream>
#include <vector>

struct RGB {
    unsigned char r,g,b;
};

void save_bitmap(const char* name, int width, int height, std::vector<RGB> pixels) {
    int padding  = (4 - (width * 3) % 4) % 4;
    int sizeData = (3 * width + padding) * height;
    int sizeFile = 54 + sizeData;

    std::ofstream out(name, std::ios::binary);
    unsigned char header[54] = {
        'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0, 40,0,0,0,
        0,0,0,0, 0,0,0,0, 1,0,24,0,
        0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0
    };
    
    header[2] = (unsigned char)(sizeFile);
    header[3] = (unsigned char)(sizeFile >> 8);
    header[4] = (unsigned char)(sizeFile >> 16);
    header[5] = (unsigned char)(sizeFile >> 24);

    header[18] = (unsigned char)(width);
    header[19] = (unsigned char)(width>> 8);
    header[20] = (unsigned char)(width>> 16);
    header[21] = (unsigned char)(width>> 24);

    header[22] = (unsigned char)(height);
    header[23] = (unsigned char)(height>> 8);
    header[24] = (unsigned char)(height>> 16);
    header[25] = (unsigned char)(height>> 24);
    
    out.write(reinterpret_cast<char*>(header), 54);
    for (int y = height - 1; y >= 0; --y) { //down 
        for (int x = 0; x < height; ++x) { //right
            const RGB& color = pixels[y * height + x];
            out.put(color.b);
            out.put(color.g);
            out.put(color.r);
        }
        for (int p = 0; p < padding; ++p)
            out.put(0);
    }

    out.close();
}

RGB color_maker(float val) {
    //this will take data from an earthquake table and then create a map
    //std::string query = select_all("stations");
    float min_val = 1500;
    float max_val = 3000;

    float t = (val-min_val) / (max_val - min_val);
    RGB color;
    color.r = static_cast<unsigned char>(t * 255);
    color.g = static_cast<unsigned char>(0);
    color.b = static_cast<unsigned char>((1-t) * 255);
    
    return color;
    //connect(query);
}


void makeMap() {
    int ancho = 256;
    int alto = 256;
    std::vector<RGB> pixels(ancho * alto);
    
    std::string val;
    std::cout << "Please insert a number.. " << std::endl;
    std::cin >> val;
    /*
    RGB color = color_maker(std::stof(val));
    std::cout << "r: " << color.r << "\ng:" << color.g << "\nb:" << color.b << std::endl;
    */

    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            pixels[y * ancho + x] = color_maker(std::stof(val));
            //pixels[y * ancho + x] = valor_a_color(valor);
        }
    }

    save_bitmap("displays/output.bmp", ancho, alto, pixels);
}
