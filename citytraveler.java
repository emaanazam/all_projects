/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author eman
 */
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class citytraveler {

    public citytraveler() {
    }

    // this is a method to find the minimum number of days to travel from city 1 to city numCities
    public static int findMinimumDays(int numCities, List<int[]> routes) {
        // Creating a graph representation of the cities using an array of ArrayLists
        ArrayList<int[]>[] cityGraph = new ArrayList[numCities];

        // initializing the graph
        for (int i = 0; i < numCities; ++i) {
            cityGraph[i] = new ArrayList<>();
        }

        // adding direct routes between cities (1 day travel for each step)
        for (int i = 0; i < numCities; ++i) {
            for (int j = 1; j <= 6 && i + j < numCities; ++j) {
                cityGraph[i].add(new int[]{i + j, 1}); // Adding a route to the next city with 1 day of travel
            }
        }

        // adding aerial routes with 0 days of travel
        for (int[] route : routes) {
            int source = route[0]; // source city
            int destination = route[1]; // destination city
            cityGraph[source].add(new int[]{destination, 0}); // add aerial route
        }

        // priority queue to explore cities based on the minimum days taken
        PriorityQueue<citynode> priorityQueue = new PriorityQueue<>();
        boolean[] visited = new boolean[numCities]; // track visited cities
        priorityQueue.add(new citynode(0, 0)); // start from city 0 with 0 days

        // main loop to process the priority queue
        while (!priorityQueue.isEmpty()) {
            citynode node = priorityQueue.poll(); // get the city with the least days
            int currentCity = node.city; // current city being processed
            int currentDays = node.days; // days taken to reach the current city

            // check if we have reached the last city
            if (currentCity == numCities - 1) {
                return currentDays; // return the number of days taken
            }

            // if the city has already been visited, skip it
            if (visited[currentCity]) {
                continue;
            }

            // mark the current city as visited
            visited[currentCity] = true;

            // process adjacent cities
            for (int[] nextCity : cityGraph[currentCity]) {
                int nextCityIndex = nextCity[0]; // next city index
                int travelDays = nextCity[1]; // days to travel to the next city

                // if the next city has not been visited, add it to the priority queue
                if (!visited[nextCityIndex]) {
                    priorityQueue.add(new citynode(nextCityIndex, currentDays + travelDays));
                }
            }
        }
        // if no path is found, return -1
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("enter no. of test cases:");
        int testCases = scanner.nextInt(); // read number of test cases

        // loop through each test case
        for (int t = 0; t < testCases; ++t) {
            System.out.println("enter no. of cities:");
            int numCities = scanner.nextInt(); // read number of cities
            System.out.println("enter no. of aerial routes:");
            int numRoutes = scanner.nextInt(); // read number of aerial routes

            List<int[]> aerialRoutes = new ArrayList<>(); // list to store aerial routes
            System.out.println("enter the aerial routes (source and destination):");

            // read each aerial route
            for (int i = 0; i < numRoutes; ++i) {
                int source = scanner.nextInt(); // source city
                int destination = scanner.nextInt(); // destination city
                aerialRoutes.add(new int[]{source, destination}); // add route to the list
            }

            // find the minimum days to travel from city 1 to city numCities
            int result = findMinimumDays(numCities, aerialRoutes);
            System.out.println("minimum no. of days to travel from city 1 to city " + numCities + ": " + result);
        }
        scanner.close();
    }
}