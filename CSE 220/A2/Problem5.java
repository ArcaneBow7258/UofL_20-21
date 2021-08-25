package assignment2;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.FlowPane;

import javafx.scene.shape.Circle;

public class Problem5 extends Application {
	final int yBound = 750;
	final int xBound = 750;
	private Circle circle1;
	private Button push;
	@Override
	public void start(Stage primaryStage) throws Exception {
		// TODO Auto-generated method stub
		//Circle
		
		circle1 = new Circle(Math.random()*xBound,Math.random()*yBound, 50);
		
		//Push Button
		push = new Button("Move Circle");
		push.setOnAction(this::processButtonPress);
		
		//Pane
		FlowPane pane = new FlowPane(circle1, push);
		pane.setAlignment(Pos.CENTER);
		
		//Grouping and setting scene
		Group root = new Group(pane, circle1);
		
		Scene scene = new Scene(root, xBound, yBound);
		//Setting Stage
		primaryStage.setTitle("Random Circle Button");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public void processButtonPress(ActionEvent event) {
		circle1.setCenterX(Math.random()*xBound);
		circle1.setCenterY(Math.random()*yBound);
	}
	public static void main(String[] args) {
		launch(args);
	}

}
