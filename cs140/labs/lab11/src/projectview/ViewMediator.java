package projectview;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;
import java.io.FileNotFoundException;
import java.util.Observable;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import project.IllegalInstructionException;
import project.MachineModel;
import project.Memory;
import project.ParityCheckException;

import project.CodeAccessException;
import project.DivideByZeroException;

public class ViewMediator extends Observable
{
	
	private MachineModel model;
	private JFrame frame;
	private StepControl stepControl;
	private CodeViewPanel codeViewPanel;
	private MemoryViewPanel memoryViewPanel1;
	private MemoryViewPanel memoryViewPanel2;
	private MemoryViewPanel memoryViewPanel3;
	private ControlPanel controlPanel;
	private ProcessorViewPanel processorPanel;
	private States currentState = States.NOTHING_LOADED;
	private FilesMgr filesMgr;
	private MenuBarBuilder menuBuilder;
	
	public MachineModel getModel()
	{
		return model;
	}
	public void setModel(MachineModel m)
	{
		model = m;
	}
	public JFrame getFrame()
	{
		return frame;
	}
	
	public void setCurrentState(States s)
	{
		if(s == States.PROGRAM_HALTED) stepControl.setAutoStepOn(false);		
		currentState = s;
		s.enter();		
		setChanged();
		notifyObservers();
	}
	
	public States getCurrentState()
	{
		return currentState;
	}
	
	private void createAndShowGUI()
	{
		stepControl = new StepControl(this);
		filesMgr = new FilesMgr(this);
		filesMgr.initialize();
		codeViewPanel = new CodeViewPanel(this, model);
		memoryViewPanel1 = new MemoryViewPanel(this, model, 0, 160);
		memoryViewPanel2 = new MemoryViewPanel(this, model, 160, Memory.DATA_SIZE/2);
		memoryViewPanel3 = new MemoryViewPanel(this, model, Memory.DATA_SIZE/2, Memory.DATA_SIZE);
		controlPanel = new ControlPanel(this);
		processorPanel = new ProcessorViewPanel(this, model);
		menuBuilder = new MenuBarBuilder(this);
		frame = new JFrame("Simulator");
		JMenuBar bar = new JMenuBar();
		frame.setJMenuBar(bar);
		bar.add(menuBuilder.createFileMenu());
		bar.add(menuBuilder.createExecuteMenu());

		Container content = frame.getContentPane(); 
		content.setLayout(new BorderLayout(1,1));
		content.setBackground(Color.BLACK);
		frame.setSize(1200,600);
		frame.add(codeViewPanel.createCodeDisplay(), BorderLayout.LINE_START);
		frame.add(processorPanel.createProcessorDisplay(),BorderLayout.PAGE_START);
		JPanel center = new JPanel();
		center.setLayout(new GridLayout(1,3));
		center.add(memoryViewPanel1.createMemoryDisplay());
		center.add(memoryViewPanel2.createMemoryDisplay());
		center.add(memoryViewPanel3.createMemoryDisplay());
		frame.add(center, BorderLayout.CENTER);
		frame.add(controlPanel.createControlDisplay(), BorderLayout.PAGE_END);
		// the next line will be commented or deleted later
		//frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		frame.addWindowListener(WindowListenerFactory.windowClosingFactory(e -> exit()));
		frame.setLocationRelativeTo(null);
		stepControl.start();
		getCurrentState().enter();
		setChanged();
		notifyObservers();
		frame.setVisible(true);
	}
	
	public void clear() 
	{
		model.clear();
		setCurrentState(States.NOTHING_LOADED);
		currentState.enter();
		setChanged();
		notifyObservers("Clear");
		model.setProgramSize(0);
	}
	
	public void toggleAutoStep()
	{
		stepControl.toggleAutoStep();
		if (stepControl.isAutoStepOn())
		{
			setCurrentState(States.AUTO_STEPPING);
		}
		
		else
		{
			setCurrentState(States.PROGRAM_LOADED_NOT_AUTOSTEPPING);
		}
	}
	
	public void reload() throws FileNotFoundException 
	{
		stepControl.setAutoStepOn(false);
		clear();
		filesMgr.finalLoad_ReloadStep();
	}
	
	public void setPeriod(int value) 
	{
		stepControl.setPeriod(value);
	}
	
	public static void main(String[] args)
	{
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				ViewMediator mediator = new ViewMediator();
				MachineModel model = new MachineModel(true, () -> 
					mediator.setCurrentState(States.PROGRAM_HALTED));
				mediator.setModel(model);
				mediator.createAndShowGUI();
			}
		});
	}
	
	public void makeReady(String s)
	{
		stepControl.setAutoStepOn(false);
		setCurrentState(States.PROGRAM_LOADED_NOT_AUTOSTEPPING);
		currentState.enter();
		setChanged();
		notifyObservers(s);
		//model.setProgramSize(0);
	}

	public void assembleFile()
	{
		filesMgr.assembleFile();
	}

	public void loadFile() throws FileNotFoundException
	{
		filesMgr.loadFile();
	}
	
	public void step() 
	{ 
		if (currentState != States.PROGRAM_HALTED && 
				currentState != States.NOTHING_LOADED) {
			try {
				model.step();
			} catch (CodeAccessException e) {
				JOptionPane.showMessageDialog(frame, 
					"Illegal access to code from line " + model.getPC() + "\n"
							+ "Exception message: " + e.getMessage(),
							"Run time error",
							JOptionPane.OK_OPTION);
				System.out.println("Illegal access to code from line " + model.getPC()); // just for debugging
				System.out.println("Exception message: " + e.getMessage());			
			} 
			catch(ArrayIndexOutOfBoundsException e)
				{
				// similar JOPtionPane
	// YOU HAVE TO FILL OUT ALL THESE CATCH BLOCKS
				JOptionPane.showMessageDialog(frame, "Illegal access to array " 
				+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
				"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(NullPointerException e)
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal access to null " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(ParityCheckException e) 
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal access to parity " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(IllegalInstructionException e)
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal instruction access " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(IllegalArgumentException e) 
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal argument access " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(DivideByZeroException e) 
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal divide by zero action " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				}
			setChanged();
			notifyObservers();
		}
	}

	public void execute()
	{
		while (currentState != States.PROGRAM_HALTED && 
				currentState != States.NOTHING_LOADED) {
			try {
				model.step();
			} catch (CodeAccessException e) {
				JOptionPane.showMessageDialog(frame, 
					"Illegal access to code from line " + model.getPC() + "\n"
							+ "Exception message: " + e.getMessage(),
							"Run time error",
							JOptionPane.OK_OPTION);
				System.out.println("Illegal access to code from line " + model.getPC()); // just for debugging
				System.out.println("Exception message: " + e.getMessage());			
			} 
			catch(ArrayIndexOutOfBoundsException e)
				{
				// similar JOPtionPane
	// YOU HAVE TO FILL OUT ALL THESE CATCH BLOCKS
				JOptionPane.showMessageDialog(frame, "Illegal access to array " 
				+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
				"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(NullPointerException e)
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal access to null " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(ParityCheckException e) 
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal access to parity " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(IllegalInstructionException e)
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal instruction access " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(IllegalArgumentException e) 
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal argument access " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				} 
			catch(DivideByZeroException e) 
				{
				// similar JOPtionPane
				JOptionPane.showMessageDialog(frame, "Illegal divide by zero action " 
						+ model.getPC() + "\n" + "Exception message: " + e.getMessage(), 
						"Run time error", JOptionPane.OK_OPTION);
				}
		}
		setChanged();
		notifyObservers();
	}
	
	public void exit()
	{
		int decision = JOptionPane.showConfirmDialog(
				frame, "Do you really wish to exit?",
				"Confirmation", JOptionPane.YES_NO_OPTION);
		if (decision == JOptionPane.YES_OPTION) {
			System.exit(0);
		}
	}

}