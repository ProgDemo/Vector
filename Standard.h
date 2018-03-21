#ifndef STANDARD_H_INCLUDED
#define STANDARD_H_INCLUDED

//Saját névtér létrehozása
namespace Standard {

    //Generikus típus T típusparaméterrel, T helyére bármilyen típus kerülhet
    template<typename T>
    class vector {

        private:
            //tömb a vektor reprezentálásához
            T* vec;
            int size;
            int maxSize;

            //Ha betelik a tömbük, foglalunk egy kétszer ekkora helyet, ha lehet, ha nem kivétel.
            void allocateMemory() {
                maxSize *= 2;
                T* new_vec = new T[maxSize];
                //new_vec null pointer lesz ha nincs több hely
                if (new_vec == 0) {
                    throw OutOfMemoryError;
                }
                for (int i = 0; i < size; ++i) {
                    new_vec[i] = vec[i];
                }
                delete[] vec;
                vec = new_vec;
            }

        public:
            enum VectorExceptions {ArrayIndexOutOfBoundsException, OutOfMemoryError};
            static const int DEFAULT_SIZE = 10;

            vector(int maxSize = DEFAULT_SIZE): maxSize(maxSize) {
                vec = new T[maxSize];
                size = 0;
            }

            void push_back(T item) {
                if (size < maxSize) {
                    vec[size++] = item;
                } else {
                    allocateMemory();
                    vec[size++] = item;
                }
            }

            const T& pop() const {
                if (size > 0) {
                    return vec[size-1];
                } else {
                    throw ArrayIndexOutOfBoundsException;
                }
            }

            T& pop() {
                if (size > 0) {
                    return vec[size-1];
                } else {
                    throw ArrayIndexOutOfBoundsException;
                }
            }

            void pop_back() {
                if (size > 0) {
                    size--;
                } else {
                    throw ArrayIndexOutOfBoundsException;
                }
            }

            const T& operator[](const int& index) const {
                if (index < size) {
                    return vec[index];
                } else {
                    throw ArrayIndexOutOfBoundsException;
                }
            }

            T& operator[](const int& index) {
                if (index < size) {
                    return vec[index];
                } else {
                    throw ArrayIndexOutOfBoundsException;
                }
            }

            int getSize() {
                return size;
            }
    };

}

#endif // STANDARD_H_INCLUDED
