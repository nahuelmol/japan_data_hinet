#ifndef MAP_H
#define MAP_H

struct RGB {
    unsigned char r,g,b;
};

void save_bitmap(const char* name, int width, int height, std::vector<RGB> pixels);
RGB color_maker(float val);
void makeMap();

#endif

