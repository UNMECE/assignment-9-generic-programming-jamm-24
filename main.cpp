#include <iostream>

template <typename T>
class GenericArray {
private:
    T* data;     
    int arraySize; 

public:
	// Constructor
    	GenericArray() : data(nullptr), arraySize(0) {}

	// Destructor
    	~GenericArray() {
        delete[] data;
    }

	//function to add element
void addElement(T element) {
     	T *new_data = new T[arraySize + 1];
        	for (int i = 0; i < arraySize; ++i) {
            	new_data[i] = data[i];
		}
        
        new_data[arraySize] = element;

        delete[] data;

        data = new_data;//update the data
        arraySize++;
}
	//function to return the value
        T at(int index){
                if (index >= 0 && index < arraySize) {
                return data[index];
        }
        std::cerr << "Error index." << std::endl;
        return T();
	}

 	//function that returns the size of the array
        int size() {
                return arraySize;
        }

	//function that return the sum of the entire array
	T sum(){
		T total= T();
		for(int i=0; i < arraySize; i++){
			total += data[i];
		}
		return total;
	}

	//max value
	T max() {
        	T maxValue = data[0];
        	for (int i = 1; i < arraySize; i++) {
            		if (data[i] > maxValue) {
                	maxValue = data[i];
            		}
        	}
        return maxValue;
    	}
	
        //min value
        T min() {
                T minValue = data[0];
                for(int i= 1; i < arraySize; i++){
                        if(data[i] < minValue){
                                minValue = data[i];
                        }
                }
                return minValue;
        }
	
        //function that returns a slice
        T* slice(int begin, int end){
                if(begin < 0 || end >= arraySize || begin > end){
                        std::cerr << "Error, slice are invalid." << std::endl;
                        return nullptr;
                }
                int sliceSize = end - begin + 1;
                T *sliced_array_data = new T[sliceSize];
                for(int i= 0; i < sliceSize; i++){
                        sliced_array_data[i]= data[begin + i];
                }
                return sliced_array_data;
        }
	};


int main(){
	GenericArray<int> int_array;
	int_array.addElement(10);
	int_array.addElement(20);
	int_array.addElement(30);
	int_array.addElement(40);
	int_array.addElement(50);
	int_array.addElement(60);

	std::cout << "Array contents: [ ";
    	for(int i = 0; i < int_array.size(); ++i) {
        	std::cout << int_array.at(i) << (i == int_array.size() - 1 ? "" : ", ");
    	}
    	std::cout << " ]" << std::endl;

    	std::cout << "size of array is " << int_array.size() << std::endl;
    	std::cout << "sum of the array is " << int_array.sum() << std::endl;
    	std::cout << "maximum and minimum of array is " << int_array.max() << "\t" << int_array.min() << std::endl;

	int *sliced_array = int_array.slice(2, 4);
	if (sliced_array != nullptr){
		std::cout << "Sliced array from index 2 to 4 is: [ ";
		for(int i= 0; i < 3; i++){
			std::cout << sliced_array[i] << (i == 2 ? "" : ", ");
		}
		std::cout << " ]" << std::endl;

		delete[] sliced_array;
	}
	return 0;
	
	}







