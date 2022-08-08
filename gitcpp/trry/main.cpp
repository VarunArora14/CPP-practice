#include<iostream>
using namespace std;
class Room;
void Area(){
    int width, height;
    class Room{
        int width, height;
    public:
        void setValue(int w, int h){
            width=w;
            height=h;
        }
        void displayValues(){
            cout<<(float)width<<' '<<(float)height;
        }
    };
    Room objRoom1;
    objRoom1.setValue(12, 8);
    objRoom1.displayValues();
}

int main(){
    Area();
}
