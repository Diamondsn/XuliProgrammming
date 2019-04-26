var len;
function heapSort(arr) {
    len = arr.length;
    buildHeap(arr);

    for (var i = arr.length - 1; i > 0; --i) {
        swap(arr, 0, i);
        len--;
        heapTiaozhen(arr, 0);
    }
    return arr;
}
function swap(arr, i1, i2) {
    var temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}
function buildHeap(arr) {
    for (var i = Math.floor(arr.length / 2); i >= 0; i--) {
        heapTiaozhen(arr, i);
    }
}

function heapTiaozhen(arr, index) {
    var left = index * 2 + 1;
    var right = index * 2 + 2;
    var largest = index;

    if (left < len && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < len && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr, index, largest);
        heapTiaozhen(arr, largest);
    }
}

console.log(heapSort([1, 6, 2, 3, 4, 8, 9, 10, 8]));