use std::io;

fn main() {
    println!("Введите год от 1970");
    let mut year_input = String::new();
    io::stdin()
        .read_line(&mut year_input)
        .expect("failed to read from stdin");
    let trimmed = year_input.trim();
    match trimmed.parse::<i32>() {
        Ok(i) => {
            let year: i32  = year_input.trim().parse::<i32>().unwrap();

            if year < 1970 {
                println!("Год должен быть больше или равен 1970");
            } else {
                println!("Введите номер месяца от 1 до 12");
                let mut mouth_input = String::new();
                io::stdin()
                    .read_line(&mut mouth_input)
                    .expect("failed to read from stdin");
                let trimmed = mouth_input.trim();
                match trimmed.parse::<i32>() {
                    Ok(i) => {
                        let mouth: i32  = mouth_input.trim().parse::<i32>().unwrap();

                        if mouth < 1 || mouth > 12 {
                            println!("Месяц должен быть в диапазоне от 1 до 12");
                        } else {
                            print_mouth(year, mouth);
                        }
                    },
                    Err(..) => println!("Ошибка: Месяц должен быть равен целому числу."),
                };
            }
        },
        Err(..) => println!("Ошибка: Год должен быть равен целому числу."),
    };
}

fn print_mouth(year: i32, mouth: i32) {
    let mut days_numbers_in_month: [i32; 12] =[ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 ];
    let mut days = 4;
    for i in 1970..year {
        days += 365;

        if i % 4 == 0 && (i % 100 != 0 || i % 400 == 0) {
            days += 1;
        }
    }

    if mouth == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        days_numbers_in_month[1] = 29;
    }

    for i in 1..mouth {
        days += days_numbers_in_month[(i - 1) as usize];
    }

    let mut day_of_week = days % 7;

    for i in 0..day_of_week {
        print!("  ");
    }

    for i in 1..=days_numbers_in_month[(mouth - 1) as usize] {
        if day_of_week <=7 {
            if i >= 10 {
                print!("{} ", i);
            } else {
                print!(" {} ", i);
            }
        } else {
            if i >= 10 {
                print!(" \n {} ", i);
            } else {
                print!(" \n {} ", i);
            }
            day_of_week -= 7;
        }
        day_of_week += 1;
    }
    println!("");

}
