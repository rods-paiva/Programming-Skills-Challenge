#include <QObject>

class TemperatureSensor : public QObject
{
    Q_OBJECT

public:
    TemperatureSensor(QObject* parent = nullptr) : QObject(parent), currentTemperature(0.0) {}

    // Signal declaration with a parameter (current temperature)
    signals:
    void temperatureChanged(double newTemperature);

public slots:
    // Function to simulate temperature reading update
    void updateTemperature(double newTemperature)
    {
        if (currentTemperature != newTemperature)
        {
            currentTemperature = newTemperature;

            // Emit the temperatureChanged signal with the new temperature value
            emit temperatureChanged(currentTemperature);
        }
    }

private:
    double currentTemperature;
};
