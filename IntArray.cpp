#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class IntArray { //class to define an integer based Array
public:
        IntArray(int size);
        ~IntArray();
        int & operator[](int i) const;
        int size() const;
        void fill(int k);
        int * begin() { //returns the first number of the array
                return data;
        }
        int * end(){ //returns the last number of the array
                return data + len;
        }
private:
        int len; 
        int * data;
};

IntArray::IntArray(int size) {
        len = size;
        data = new int[len];
}

IntArray::~IntArray() {
        data = NULL;
        delete data;
}
int & IntArray::operator[](int i) const {
        return data[i];
}
int IntArray::size() const {
        return len;
}
void IntArray::fill(int k) {  //fills the entire array with a given number
        for(int i = 0; i < len; i++)
                data[i] = k;
}
void test1(){ //test for creating array
	IntArray a(3);
	a[0] = 10;
	a[1] = 11;
	a[2] = 12;
	assert(a.size() == 3);
}
void test2(){ //tests fill function
	IntArray b(5);
	b.fill(7);
	assert(b[0] == 7);
	assert(b[1] == 7);
	assert(b[2] == 7);
	assert(b[3] == 7);
	assert(b[4] == 7);
}
void test3(){ //tests sort
	IntArray c(3);
	c[0] = 3;
	c[1] = 1;
	c[2] = 2;
	sort(c.begin(), c.end());
	assert(c[0] == 1);
	assert(c[1] == 2);
	assert(c[2] == 3);
}
void test4(){ //tests pointer to the array, begin and end function
	IntArray d(3);
	d[0] = 1;
	d[1] = 2;
	d[2] = 3;
	int * it = d.begin();
	assert(*it == 1);
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(it == d.end());
}
int main(int argc, char * args[]) {
	test1();
	test2();
	test3();
	test4();
        cout << "All Tests Passed." << endl;
}
