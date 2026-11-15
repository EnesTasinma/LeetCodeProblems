package LeetCodeProblems.CarFleet;

import java.util.Arrays;
import java.util.Comparator;

public class Solution {

    static class Car {
        Car(int x, int y) {
            speed = x;
            position = y;
        }

        int speed;
        int position;
    }

    public int carFleet(int target, int[] position, int[] speed) {
        Car[] array = new Car[position.length];
        for (int i = 0; i < position.length; i++) {
            Car car = new Car(speed[i], position[i]);
            array[i] = car;
        }
        Arrays.sort(array, Comparator.comparingInt(x -> x.position));
        int counter = 0;
        double max = 0.0;
        for (int i = array.length - 1; i >= 0; i--) {
            double time = (double) ((target - array[i].position) / array[i].speed);
            if (time > max) {
                counter++;
                max = time;
            }
        }
        return counter;
    }
}
