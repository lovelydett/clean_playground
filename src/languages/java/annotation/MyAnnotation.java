package languages.java.annotation;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.annotation.ElementType;

// this is a custom annotation for class
@Retention(RetentionPolicy.RUNTIME) // RetentionPolicy.RUNTIME means this annotation will be kept in the class file
                                    // and can be read reflectively
@Target(ElementType.TYPE) // ElementType.TYPE means this annotation can only be used on class, interface,
                          // enum, or annotation
public @interface MyAnnotation {
    // this is an empty annotation, just a tag
}
