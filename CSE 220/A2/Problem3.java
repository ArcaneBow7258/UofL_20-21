package assignment2;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class Problem3 extends Application{
	
	public void start(Stage primaryStage) {
		Circle circle = new Circle(200, 200, Math.random()*100 + 50);
		
		Group single = new Group(circle);
		Scene scene = new Scene(single, 500, 500, Color.AZURE);
		
		primaryStage.setTitle("Problem 3, Random Circle");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
