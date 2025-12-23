import java.util.*;

// Patient class implementing Comparable to sort by priority
class Patient implements Comparable<Patient> {
    String name;
    int priority; // 3 = High, 2 = Medium, 1 = Low

    public Patient(String name, int priority) {
        this.name = name;
        this.priority = priority;
    }

    @Override
    public int compareTo(Patient other) {
        // Higher priority first
        return Integer.compare(other.priority, this.priority);
    }

    @Override
    public String toString() {
        String level;
        switch (priority) {
            case 3: level = "High"; break;
            case 2: level = "Medium"; break;
            default: level = "Low"; break;
        }
        return "Patient: " + name + " | Concern Level: " + level;
    }
}

// Main hospital appointment system class
public class HospitalAppointmentSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PriorityQueue<Patient> pq = new PriorityQueue<>();

        while (true) {
            System.out.println("\n=== HOSPITAL APPOINTMENT SYSTEM ===");
            System.out.println("1. Add new patient");
            System.out.println("2. Serve next patient");
            System.out.println("3. View waiting list");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter patient name: ");
                    String name = sc.nextLine();

                    System.out.print("Enter level of concern (1=Low, 2=Medium, 3=High): ");
                    int priority = sc.nextInt();

                    if (priority < 1 || priority > 3) {
                        System.out.println("Invalid priority level!");
                    } else {
                        pq.add(new Patient(name, priority));
                        System.out.println("Patient added successfully!");
                    }
                    break;

                case 2:
                    if (pq.isEmpty()) {
                        System.out.println("No patients waiting.");
                    } else {
                        Patient next = pq.poll();
                        System.out.println("\nServing patient now:");
                        System.out.println(next);
                    }
                    break;

                case 3:
                    if (pq.isEmpty()) {
                        System.out.println("No patients in the queue.");
                    } else {
                        System.out.println("\n--- Current Waiting List ---");
                        for (Patient p : pq)
                            System.out.println(p);
                    }
                    break;

                case 4:
                    System.out.println("Exiting system. Stay healthy!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }
}
