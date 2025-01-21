#include "SimClient.hpp"  // Подключаем заголовочный файл из вашей библиотеки
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // Создаем объект Client с использованием конструктора
    //Client client("127.0.0.1", 8080);

    // Выводим данные клиента
    //client.PrintData();

    Mat image;
    image = imread("C:/Users/Senya/Desktop/sql_string.png");
    if ( ! image.data )
    {
        printf("No image data Xn");
        return -1;
    }
    namedWindow( "Display Image", WINDOW_AUTOSIZE ) ;
    imshow( "Display Image" , image);
    waitKey(0);
    
    return 0;
}