package conversion.mass;

public class ImperialToMetric {
    
}

class CookingMeasurementConversions {
    
    double OuncesToMilligrams(int ounces) {
        return ounces * 28349.5;
    }

    double OuncesToGrams(int ounces) {
        return ounces * 28.35;
    }

    double PoundsToGrams(int pounds) {
        return pounds * 453.592;
    }
}

class WeightConversions {
    
    double PoundsToKilograms(int pounds) {
        return pounds / 2.205;
    }

    double OuncesToKilograms(int ounces) {
        return ounces / 35.274;
    }

    double StonesToKilograms(int stones) {
        return stones * 6.35;
    }
}