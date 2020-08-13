use rand::Rng;

fn random_partition(arr: &mut[i32]) -> usize{
    let rnd = rand::thread_rng().gen_range(0, arr.len());
    let end = (arr.len() - 1) as usize;
    arr.swap(rnd, end);
    let mut i = 0;
    for j in 0..end {
        if arr[j] <= arr[end] {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, end);
    return i;
}


fn quickselect(arr: &mut[i32], index: usize) -> i32 {
    if arr.len() == 1 {
        return arr[0];
    }
    else if arr.len() == 0 {
        return -1;
    }
    else {
        let pivot = random_partition(arr);
        println!("random pivot index {}", pivot);
        if index == pivot {
            return arr[pivot];
        }
        else if index < pivot {
            return quickselect(&mut arr[0..pivot-1], index);
        }
        else {
            return quickselect(&mut arr[pivot+1..], index - pivot);
        }
    }
}





fn view_array(arr: &mut[i32]) {
    for elem in arr.iter() {
        print!("{} ", elem);
    }
}

fn main() {
    let index: usize = 3;
    let mut x = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    // println!("The random index is {}", random_partition(&mut x));
    println!("The {}-th order statistic is: {}", index, quickselect(&mut x, index));
    view_array(&mut x);
}



