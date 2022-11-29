#include <fstream>

class Config_Import {
private:
public:
    static int* file(std::string& path) {
        std::ifstream config(path);

        if (!config) {
            std::cout << "ERROR" << std::endl;
            return nullptr;
        } else {
            int x;
            int y;
            config >> x;
            config >> y;
            int* file = new int[x*y + 2];
            file[0] = x;
            file[1] = y;
            for (int i = 0; i < x*y; i++) {
                int tmp;
                config >> tmp;
                file[i + 2] = tmp;
            }
            return file;
        }
    }

    static int x_size(int* file) {
        return file[0];
    }

    static int y_size(int* file) {
        return file[1];
    }

    static int* data(int* file) {
        int size = x_size(file)* y_size(file);
        int* data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = file[i + 2];
        }
        return data;
    }
};
