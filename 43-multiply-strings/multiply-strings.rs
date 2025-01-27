impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        let num1_chars: Vec<char> = num1.chars().collect();
        let num2_chars: Vec<char> = num2.chars().collect();

        let mut significant_magnitude_list: Vec<(u32,usize)> = vec![];
        for a in 0..num1_chars.len(){
            for b in 0..num2_chars.len(){

                
                let product = num1_chars[a].to_digit(10).unwrap() * num2_chars[b].to_digit(10).unwrap();
                let carry = product / 10;
                let rest = product % 10;

                let magnitude_a = num1_chars.len() -a;
                let magnitude_b = num2_chars.len() -b;
                let total_magnitude = magnitude_a + magnitude_b;
                if rest > 0{
                    significant_magnitude_list.push((rest, total_magnitude-1));
                }
                if carry > 0{
                    significant_magnitude_list.push((carry, total_magnitude));
                }
            }
        }
        significant_magnitude_list.sort_by(|a, b| a.1.cmp(&b.1));


        let mut output: String = String::from("");
        let mut carry = 0;
        let mut significant = 1;
        if significant_magnitude_list.len() < 1{
            return "0".to_string();
        }
        while significant <= significant_magnitude_list[significant_magnitude_list.len()-1].1 || carry > 0{
            let mut sum: u32 = 0;
            sum += significant_magnitude_list.iter()
                      .filter(|&&(_, b)| b == significant)
                      .map(|&(a, _)| a)
                      .sum::<u32>();
            sum += carry;

            carry = sum / 10;
            let rest = sum % 10;
            significant +=1;
            output.push_str(rest.to_string().as_str());
            
        }
        output.chars().rev().collect()
    
    }
}