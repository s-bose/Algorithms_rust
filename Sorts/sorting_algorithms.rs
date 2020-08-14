
fn insertion_sort(arr: &mut[i32]) {
    let end = arr.len();
    for j in 1..end {
        let key = arr[j];
        let mut i = (j as i32) - 1;
        while i >= 0 && arr[i as usize] > key {
            arr[(i + 1) as usize] = arr[i as usize];
            i -= 1;
        }
        arr[(i + 1) as usize] = key;
    }
}

fn merge(arr: &mut[i32], left: usize, mid: usize, right: usize) {
    let n1 = mid - left + 1;
    let n2 = right - mid; 

    let mut left_arr = Vec::new();
    let mut right_arr = Vec::new();
    for i in 0..n1 {
        left_arr.push(arr[left + i]);
    }
    for i in 0..n2 {
        right_arr.push(arr[mid + 1 + i]);   
    }
    let mut i = 0;
    let mut j = 0;
    let mut k = left;

    while i < n1 && j < n2 {
        if left_arr[i] <= right_arr[j] {
            arr[k] = left_arr[i];
            i += 1;
        } else {
            arr[k] = right_arr[j];
            j += 1;
        }
        k += 1;
    }

    while i < n1 {
        arr[k] = left_arr[i];
        i += 1;
        k += 1;
    }

    while j < n2 {
        arr[k] = right_arr[j];
        j += 1;
        k += 1;
    }
}

fn merge_sort(arr: &mut[i32], left: usize, right: usize) {
    if left < right {
        let mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

fn main() {
    let mut arr = vec![4, 3, 2, 10, 12, 1, 5, 6];
    let len = arr.len();
    merge_sort(&mut arr, 0, len - 1);
    display_array(&mut arr);
}

fn display_array(arr: &mut[i32]) {
    println!("{:?}", arr);
}
