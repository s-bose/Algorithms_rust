
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

fn main() {
    let mut arr = vec![4, 3, 2, 10, 12, 1, 5, 6];
    insertion_sort(&mut arr);
    display_array(&mut arr);
}

fn display_array(arr: &mut[i32]) {
    for x in arr {
        print!("{} ", x);
    }
    println!();
}
