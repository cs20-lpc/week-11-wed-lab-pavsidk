template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    int i = 0;
    int index;
    while (i<M) {
        index = probeIndex(key, i);
        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = 1;
            N++;
            return index;
        }
        i++;
    }
    return -1;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    // TO DO: 
    int i = 0;
    int index;
    while (i < M) {
        index = probeIndex(key, i);
        if (occupied[index] && key == table[index]) {
            return {true, index};
        }
        i++;
    }
    return {false, 0};
}
