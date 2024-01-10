/**
 * @fileoverview this is the entry of the testing the annotation in Java
 */

package languages.java.annotation;

import languages.java.annotation.MyAnnotation;

@MyAnnotation
class AnnotatedClass {
    public void testMethod() {
        System.out.println("this is an annotated class");
    }
}

class Test {
    public static void checkIsAnnotated(Object object) {
        Class<?> clazz = object.getClass();
        if (clazz.isAnnotationPresent(MyAnnotation.class)) {
            System.out.println("this class is annotated");
        } else {
            System.out.println("this class is not annotated");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        AnnotatedClass annotatedClass = new AnnotatedClass();
        Test.checkIsAnnotated(annotatedClass);
    }
}