#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>

using namespace std;

const int width = 80;
const int height = 50;
const double PI = 3.14159265;

char screen[height][width];

void clear_screen() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            screen[i][j] = ' ';
        }
    }
}

void draw(int x, int y) {
    double z[height][width] = { 0 };
    double A = 1, B = 1;
    for (double theta = 0; theta < 2 * PI; theta += 0.02) {
        for (double phi = 0; phi < 2 * PI; phi += 0.01) {
            double sin_theta = sin(theta);
            double cos_theta = cos(theta);
            double sin_phi = sin(phi);
            double cos_phi = cos(phi);
            double circle_x = cos_phi + 2;
            double circle_y = sin_phi;
            double zed = sin_theta * circle_x + cos_theta * circle_y;
            double f = 1 / zed;
            double x_proj = (f * A * circle_x) + x;
            double y_proj = (f * B * circle_y) + y;
            int x_pixel = (int)(x_proj + 0.5);
            int y_pixel = (int)(y_proj + 0.5);
            if (x_pixel >= 0 && x_pixel < width && y_pixel >= 0 && y_pixel < height && zed > z[y_pixel][x_pixel]) {
                z[y_pixel][x_pixel] = zed;
                int luminance_index = (int)(((cos_phi * sin_theta) + (cos_theta * sin_phi)) * 8);
                if (luminance_index < 0) {
                    luminance_index = 0;
                }
                if (luminance_index > 7) {
                    luminance_index = 7;
                }
                screen[y_pixel][x_pixel] = ".,-~:;=!*#$@"[luminance_index];
            }
        }
    }
}

int main() {
    int x = width / 2;
    int y = height / 2;
    while (true) {
        clear_screen();
        draw(x, y);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << screen[i][j];
            }
            cout << endl;
        }
        x += 2;
        y += 1;
        usleep(50000);
        system("clear");
    }
    return 0;
}
