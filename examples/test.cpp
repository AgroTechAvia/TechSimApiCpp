#include "SimClient.hpp"  // Подключаем заголовочный файл из вашей библиотеки
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
    // Создаем объект Client с использованием конструктора

    try
    {
        Client client("127.0.0.1", 8080);

        // Выводим данные клиента
        bool isConnect = client.IsConnected();

        std::cout << "The result is: " << isConnect << std::endl;
    }
    catch(const char* error_message)
    {
        std::cout << error_message  << std::endl;
    }

    return 0;
}