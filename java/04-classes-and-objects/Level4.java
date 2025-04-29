public class Level4 {
    public static void main(String[] args) {
        Car car = new Car(1998, 235000, "Golf IV", "VW");

        car.beep();

        System.out.println(car.getDescriptor());

        car.revertKilometers();

        System.out.println(car.getDescriptor());
    }
}

class Car {
    private int year;
    private int kilometers;
    private String model;
    private String brand;

    public Car(int year, int kilometers, String model, String brand) {
        this.year = year;
        this.kilometers = kilometers;
        this.model = model;
        this.brand = brand;
    }

    public void beep() {
        System.out.println("Beep!");
    }

    public void revertKilometers() {
        this.kilometers -= 50000;
    }

    public String getDescriptor() {
        return brand + " " + model + " - " + year + " (" + kilometers + "km)";
    }
}
