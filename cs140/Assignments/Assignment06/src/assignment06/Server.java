package assignment06;

public class Server {

	private MComp allMenus;
	
	public Server(MComp menus)
	{
		allMenus = menus;
	}
	
	
	public void printMenu()
	{
		System.out.println( "\nALL MENUS\n----");
		for(MComp comp : allMenus){
			comp.print();
		}
		
	}
	
	public void  printVegetarianMenu(){
		System.out.println( "\nVEGETARIAN MENU\n----");
		for(MComp comp : allMenus)
		{
			if(comp instanceof MenuItem)
			{
				MenuItem m = (MenuItem)comp;
				if(m.isVegetarian())
					m.print();
				}
		}
	}
		
			
	
	
	
}
