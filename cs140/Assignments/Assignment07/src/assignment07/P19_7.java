package assignment07;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;



public class P19_7 {
	public static void main(String[] args) throws IOException{

		try (Stream<String> lines = Files.lines(Paths.get("fem1stnames.txt"))) 
		{

			long count = lines
					.filter(str -> {
						int counter =0;
						for(int i =0; i< str.length(); i++)
						{
							if(str.toUpperCase().charAt(i) == 'A' || str.toUpperCase().charAt(i) == 'E'||str.toUpperCase().charAt(i) == 'I'||str.toUpperCase().charAt(i) == 'O' ||str.toUpperCase().charAt(i) == 'U')
								counter++;

						}
						return counter <=2;
					}) // Keep only female with at most 2 vowels

					.count();
			System.out.println(count);;

		}

		try (Stream<String> lines = Files.lines(Paths.get("fem1stnames.txt"))) 
		{

			Optional<String> result = lines
					.filter(str -> {
						int counter =0;
						for(int i =0; i< str.length(); i++)
						{
							if(str.toUpperCase().charAt(i) == 'A' || str.toUpperCase().charAt(i) == 'E'||str.toUpperCase().charAt(i) == 'I'||str.toUpperCase().charAt(i) == 'O' ||str.toUpperCase().charAt(i) == 'U')
								counter++;

						}
						return counter <=2;
					}) // Keep only female with at most 2 vowels
					.max((v,w)->v.length()-w.length());
			System.out.println(result);

		}
		try (Stream<String> lines = Files.lines(Paths.get("fem1stnames.txt"))) 
		{

			Map<Integer,Long> test = lines.filter(str -> {
				int counter =0;
				for(int i =0; i< str.length(); i++)
				{
					if(str.toUpperCase().charAt(i) == 'A' || str.toUpperCase().charAt(i) == 'E'||str.toUpperCase().charAt(i) == 'I'||str.toUpperCase().charAt(i) == 'O' ||str.toUpperCase().charAt(i) == 'U')
						counter++;

				}
				return counter <=2;
			})
					// Keep only female with at most 2 vowels
					.collect(Collectors.groupingBy(w -> w.length(), Collectors.counting()));

			for(Integer peopleCount : test.keySet()) 
			{ 
				if(test.get(peopleCount) ==1) 	 
					System.out.println("There is " + test.get(peopleCount)+" person" + " with "+ peopleCount + " letters in their name"); 
				else
					System.out.println("There are " + test.get(peopleCount)+" people" + " with "+ peopleCount + " letters in their name"); 
			}





		}
		try (Stream<String> lines = Files.lines(Paths.get("male1stnames.txt"))) 
		{

			// Stream<String> stream = lines;
			Map<String, List<String>> maleNames = lines.collect(Collectors.groupingBy(w -> w.substring(0, 1)));
			for(String s : maleNames.keySet()) {
				System.out.println(maleNames.get(s));
			}
		}
	}

}