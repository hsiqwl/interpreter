#ifndef INTERPRETER_MAP_ITERATOR_H
#define INTERPRETER_MAP_ITERATOR_H
#include <type_traits>

class Map;
class Cell;

template<bool is_const>
class MapIterator {
private:
    typedef std::conditional_t<is_const, const Cell, Cell>* elem_ptr;

    elem_ptr ptr_;

    MapIterator(elem_ptr ptr): ptr_(ptr) {}

    friend class Map;

    friend class MapIterator<!is_const>;

public:
    typedef std::conditional_t<is_const, const Cell, Cell>* pointer;

    typedef std::conditional_t<is_const, const Cell, Cell>& reference;

    template<bool other_const>
    MapIterator(const MapIterator<other_const>& other) noexcept requires (is_const >= other_const) {
        ptr_ = other.ptr_;
    }

    template<bool other_const>
    MapIterator(MapIterator<other_const>&& other) noexcept requires (is_const >= other_const) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    template <bool other_const>
    MapIterator& operator = (const MapIterator<other_const>& other) noexcept requires (is_const >= other_const) {
        ptr_ = other.ptr_;
        return *this;
    }

    template<bool other_const>
    MapIterator& operator = (MapIterator<other_const>&& other) noexcept requires (is_const >= other_const) {
        if (&other != this) {
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    pointer operator -> () const noexcept {
        return ptr_;
    }

    reference operator * () const noexcept {
        return *ptr_;
    }

    template<bool other_const>
    bool operator == (const MapIterator<other_const>& other) const noexcept {
        return ptr_ == other.ptr_;
    }

    template <bool other_const>
    bool operator < (const MapIterator<other_const>& other) const noexcept {
        return ptr_ < other.ptr_;
    }

    template <bool other_const>
    bool operator > (const MapIterator<other_const>& other) const noexcept {
        return ptr_ > other.ptr_;
    }

    MapIterator& operator ++ () noexcept {
        ++ptr_;
        return *this;
    }

    MapIterator operator ++ (int) noexcept {
        MapIterator iterator(ptr_);
        ++ptr_;
        return iterator;
    }

    MapIterator& operator -- () noexcept {
        --ptr_;
        return *this;
    }

    MapIterator operator -- (int) noexcept {
        MapIterator iterator(ptr_);
        --ptr_;
        return *this;
    }

    MapIterator operator + (std::size_t n) const noexcept {
        return {ptr_ + n};
    }

    MapIterator operator - (std::size_t n) const noexcept {
        return {ptr_ - n};
    }

    MapIterator& operator += (std::size_t n) noexcept {
        ptr_ += n;
        return *this;
    }

    MapIterator& operator -= (std::size_t n) noexcept {
        ptr_ -= n;
        return *this;
    }
};

#endif //INTERPRETER_MAP_ITERATOR_H
