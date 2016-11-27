mod temperature;
use temperature::*;

fn main() {
    let mut t = Temperature::new();

    t.set_kelvin(273.15);

    assert_eq!(t.get(TempScale::K), 273.15);
    assert_eq!(t.get(TempScale::C), 0.0);
    assert_eq!(t.get(TempScale::F), 32.0);

    t.set_celcius(32.0);
    assert_eq!(t.get(TempScale::K), 305.15);
    assert_eq!(t.get(TempScale::C), 32.0);

    t.set_fahrenheit(32.0);
    assert_eq!(t.get(TempScale::F), 32.0);
    assert_eq!(t.get(TempScale::C), 0.0);
    assert_eq!(t.get(TempScale::K), 273.15);
}
