public class InvokeDemo implements Runnable {
	public static void main(String [] args) {
		new InvokeDemo().test();
	}
	
	public void test() {
		InvokeDemo.staticMethod();
		InvokeDemo demo = new InvokeDemo();
		demo.instanceMethod();
		super.equals(null);
		this.run();
		((Runnable)demo).run();
	}
	
	public static void staticMethod() {}
	private void instanceMethod() {}
	@Override public void run() {}
}
