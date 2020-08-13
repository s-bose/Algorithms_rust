use rand::{Rng, thread_rng};
use rand::seq::SliceRandom;



fn partition(arr: &mut[i32], begin: usize, end: usize) -> usize {
    let mut i = begin;
    for j in begin..end {
        if arr[j] <= arr[end] {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, end);
    return i;
}

fn random_partition(arr: &mut[i32], begin: usize, end: usize) -> usize {
    let rnd_index = rand::thread_rng().gen_range(begin, end+1);
    arr.swap(rnd_index, end);
    return partition(arr, begin, end);
}  

fn find_order_stat(arr: &mut[i32], begin: usize, end: usize, order: usize) -> i32 {
    let count = end - begin + 1;
    if order < begin || order > end {
        println!("Please enter an order between {} and {}", begin, end);
        return 0;
    }
    else if count == 1 {
        return arr[begin];
    }

    let pivot = random_partition(arr, begin, end);
    if pivot == order {
        // order stat found
        println!("The {}-th order statistic is: {}", order, arr[pivot]);
        return arr[pivot];
    }
    else if order < pivot {
        return find_order_stat(arr, begin, pivot-1, order);
    }
    else {
        return find_order_stat(arr, pivot, end, order);
    }

}


fn main() {
    let mut arr: Vec<i32> = (10..21).collect();
    arr.shuffle(&mut thread_rng());
    println!("initial array: ");
    display_array(&mut arr);
    let end = arr.len() - 1;
    random_partition(&mut arr, 0, end);

    println!("{}", "\n\n\n");
    find_order_stat(&mut arr, 0, end, 4);
}

fn display_array(arr: &mut[i32]) {
    for x in arr {
        print!("{} ", x);
    }
    println!();
}
