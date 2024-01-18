package com.lovelydett.app;

/**
 * This is a simulated vending machine composed using Spring's IoC and DI
 * @author Yuting Xie
 * @date 2024-01-18
 */

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class App {
    public static void main(String[] args) {
        System.out.println("Program starts");

        // create a Spring IoC container from the XML configuration file
        ApplicationContext context = new ClassPathXmlApplicationContext("beans.xml");

        // get the VendingMachine bean from the container
        VendingMachine vendingMachine = (VendingMachine) context.getBean("vendingMachine");

        // Invoke the methods on the VendingMachine bean
        vendingMachine.showProducts();
        Product product = vendingMachine.selectProduct(2);
        vendingMachine.purchase(product, 10);

        System.out.println("Program finished");
    }
}
