/*MIT License
Copyright (c) 2020 Nyameaama Gambrah
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include"SD.h"

//Operation functions
//Input
char* inputDatafromSD(char* filename){
    File temp;
    temp = SD.open(filename,FILE_READ);
    char* buffer;
    if(temp){
        while(temp.available()){
            buffer = temp.read();
        }
    }
    return buffer;
}
//Output
void outputDatatoSD(char* filename,char* data){
    //Output data to SD
    File temp;
    temp = SD.open(filename,FILE_WRITE);
    temp.print(data);
    temp.close();
}
//Create
void createfileOnSD(char* filename){
    //Create File 
    File tempCreate;
    tempCreate = SD.open(filename,FILE_WRITE);
    tempCreate.close();
}
//Remove
void deletefileOnSD(char* filename){
    SD.remove(file);
}