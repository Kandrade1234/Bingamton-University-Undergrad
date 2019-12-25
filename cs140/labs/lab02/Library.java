package lab02;
public class Library
{
	public static void main(String[] args) {
Book library[] = new Book[3];
library[0] = new Book ("Moby Dick" , 450);
library[1] = new Book ("Of Mice and Men" ,100);
library[2] = new Book ("The Best C++" , 100);


System.out.println("Titles:  ");

for(int i =0; i < library.length; i++)
	{ System.out.println(library[i].getTitle());

	}
System.out.println("\nPages:  ");

for (Book currentElement : library) {
    System.out.println(currentElement.getNumPages());
	}





System.out.print("Expected: 650 total pages ");
System.out.print("\nCalculated: ");
System.out.println(numPagesInLibrary(library));
System.out.print("\nExpected: 450 is the book with the most pages ");
System.out.print("\nCalculated: ");

System.out.println(mostPages(library));


}

public static int numPagesInLibrary(Book[] books)
{
int totalPages =0; 
for(int i =0; i < books.length; i++)
{
	totalPages+= books[i].getNumPages(); 
}
return totalPages; 

}

public static int mostPages(Book[] books)
{
	int max = 0; 
for(int i =0; i < books.length; i++)
{
	if (max < books[i].getNumPages())
		max = books[i].getNumPages();
	
}

		return max;
	}
}
