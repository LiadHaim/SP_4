// liadi.haim@gmail.com
#ifndef MYCONTAINER_HPP
#define MYCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace MyNamespace {

template<typename T = int>
class MyContainer {
private:
    std::vector<T> elements;

public:
    // Constructor
    MyContainer() = default;
      MyContainer(std::initializer_list<T> init) 
        : elements(init) {}
    
    // Copy constructor
    MyContainer(const MyContainer& other) : elements(other.elements) {}
    
    // Assignment operator
    MyContainer& operator=(const MyContainer& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }
    
    // Destructor
    ~MyContainer() = default;

    // Add element
    void add(const T& element) {
        elements.push_back(element);
    }

    // Remove element (all occurrences)
    void remove(const T& element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it == elements.end()) {
            throw std::runtime_error("Element not found in container");
        }
        
        elements.erase(
            std::remove(elements.begin(), elements.end(), element),
            elements.end()
        );
    }

    // Get size
    size_t size() const {
        return elements.size();
    }

    // Check if empty
    bool empty() const {
        return elements.empty();
    }

    // Access element by index
    const T& operator[](size_t index) const {
        if (index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    // Get copy of elements vector
    std::vector<T> getElements() const {
        return elements;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const MyContainer& container) {
        os << "[";
        for (size_t i = 0; i < container.elements.size(); ++i) {
            os << container.elements[i];
            if (i < container.elements.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    // Iterator classes
    class AscendingOrder {
    private:
        std::vector<T> sorted_elements;
        size_t current_index;

    public:
        AscendingOrder(const MyContainer& container) : current_index(0) {
            sorted_elements = container.elements;
            std::sort(sorted_elements.begin(), sorted_elements.end());
        }

        class iterator {
        private:
            const std::vector<T>* elements;
            size_t index;

        public:
            iterator(const std::vector<T>* elem, size_t idx) : elements(elem), index(idx) {}

            const T& operator*() const {
                return (*elements)[index];
            }

            iterator& operator++() {
                ++index;
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return index != other.index;
            }

            bool operator==(const iterator& other) const {
                return index == other.index;
            }
        };

        iterator begin() const {
            return iterator(&sorted_elements, 0);
        }

        iterator end() const {
            return iterator(&sorted_elements, sorted_elements.size());
        }
    };

    class DescendingOrder {
        // This class provides a descending order iterator for the container.
    private:
        std::vector<T> sorted_elements;

    public:
        DescendingOrder(const MyContainer& container) {
            sorted_elements = container.elements;
            std::sort(sorted_elements.begin(), sorted_elements.end(), std::greater<T>());
        }

        class iterator {
        private:
            const std::vector<T>* elements;
            size_t index;

        public:
            iterator(const std::vector<T>* elem, size_t idx) : elements(elem), index(idx) {}

            const T& operator*() const {
                return (*elements)[index];
            }

            iterator& operator++() {
                ++index;
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return index != other.index;
            }

            bool operator==(const iterator& other) const {
                return index == other.index;
            }
        };

        iterator begin() const {
            return iterator(&sorted_elements, 0);
        }

        iterator end() const {
            return iterator(&sorted_elements, sorted_elements.size());
        }
    };

    class SideCrossOrder {
        // This class provides a side-cross order iterator for the container.
    private:
        std::vector<T> cross_elements;

    public:
        SideCrossOrder(const MyContainer& container) {
            std::vector<T> sorted = container.elements;
            std::sort(sorted.begin(), sorted.end());
            
            size_t left = 0, right = sorted.size() - 1;
            bool take_left = true;
            
            while (left <= right) {
                if (take_left) {
                    cross_elements.push_back(sorted[left++]);
                } else {
                    cross_elements.push_back(sorted[right--]);
                }
                take_left = !take_left;
                
                if (left > right) break;
            }
        }

        class iterator {
            // This class provides an iterator for the SideCrossOrder container.
        private:
            const std::vector<T>* elements;
            size_t index;

        public:
            iterator(const std::vector<T>* elem, size_t idx) : elements(elem), index(idx) {}

            const T& operator*() const {
                return (*elements)[index];
            }

            iterator& operator++() {
                ++index;
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return index != other.index;
            }

            bool operator==(const iterator& other) const {
                return index == other.index;
            }
        };

        iterator begin() const {
            return iterator(&cross_elements, 0);
        }

        iterator end() const {
            return iterator(&cross_elements, cross_elements.size());
        }
    };

    class ReverseOrder {
        // This class provides a reverse order iterator for the container.
    private:
        const MyContainer* container;

    public:
        ReverseOrder(const MyContainer& cont) : container(&cont) {}

        class iterator {
        private:
            const MyContainer* container;
            int index;

        public:
            iterator(const MyContainer* cont, int idx) : container(cont), index(idx) {}

            const T& operator*() const {
                return (*container)[index];
            }

            iterator& operator++() {
                --index;
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return index != other.index;
            }

            bool operator==(const iterator& other) const {
                return index == other.index;
            }
        };

        iterator begin() const {
            return iterator(container, container->size() - 1);
        }

        iterator end() const {
            return iterator(container, -1);
        }
    };

    class Order {
    private:
        const MyContainer* container;

    public:
        Order(const MyContainer& cont) : container(&cont) {}

        class iterator {
        private:
            const MyContainer* container;
            size_t index;

        public:
            iterator(const MyContainer* cont, size_t idx) : container(cont), index(idx) {}

            const T& operator*() const {
                return (*container)[index];
            }

            iterator& operator++() {
                ++index;
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return index != other.index;
            }

            bool operator==(const iterator& other) const {
                return index == other.index;
            }
        };

        iterator begin() const {
            return iterator(container, 0);
        }

        iterator end() const {
            return iterator(container, container->size());
        }
    };

    class MiddleOutOrder {
    private:
        std::vector<T> middle_out_elements;

    public:
        MiddleOutOrder(const MyContainer& container) {
            if (container.empty()) return;
            
            std::vector<size_t> indices;
            size_t size = container.size();
            size_t middle = size / 2;
            
            // Start with middle element
            indices.push_back(middle);
            
            // Add elements alternating left and right
            int left = middle - 1;
            int right = middle + 1;
            bool go_left = true;
            
            while (left >= 0 || right < static_cast<int>(size)) {
                if (go_left && left >= 0) {
                    indices.push_back(left--);
                } else if (!go_left && right < static_cast<int>(size)) {
                    indices.push_back(right++);
                }
                go_left = !go_left;
            }
            
            // Build the elements vector
            for (size_t idx : indices) {
                middle_out_elements.push_back(container[idx]);
            }
        }

        class iterator {
            // This class provides an iterator for the MiddleOutOrder container.
        private:
            const std::vector<T>* elements;
            size_t index;

        public:
            iterator(const std::vector<T>* elem, size_t idx) : elements(elem), index(idx) {}

            const T& operator*() const {
                return (*elements)[index];
            }

            iterator& operator++() {
                ++index;
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return index != other.index;
            }

            bool operator==(const iterator& other) const {
                return index == other.index;
            }
        };

        iterator begin() const {
            return iterator(&middle_out_elements, 0);
        }

        iterator end() const {
            return iterator(&middle_out_elements, middle_out_elements.size());
        }
    };
};

} 
#endif 