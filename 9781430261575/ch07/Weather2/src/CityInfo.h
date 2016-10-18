/*
 * City.h
 *
 *  Created on: Dec 10, 2013
 *      Author: aludin
 */

#ifndef CITY_H_
#define CITY_H_
#include <QObject>
#include <bb/cascades/Image>
#include <QNetworkAccessManager>

class CityInfo : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString city READ city NOTIFY cityChanged)
	Q_PROPERTY(QString state READ state NOTIFY stateChanged)
	Q_PROPERTY(QString latitude READ latitude NOTIFY latitudeChanged)
	Q_PROPERTY(QString longitude READ longitude NOTIFY longitudeChanged)
	Q_PROPERTY(QString weather READ weather NOTIFY weatherChanged)
	Q_PROPERTY(QVariant weatherIcon READ weatherIcon NOTIFY weatherIconChanged)
	Q_PROPERTY(QString temperature READ temperature NOTIFY temperatureChanged)
	Q_PROPERTY(QString lastObservation READ lastObservation NOTIFY lastObservationChanged)

public:
	CityInfo(QObject* parent = 0);
	virtual ~CityInfo();

	void setCoordinates(const QString& latitude, const QString& longitude, QString weatherIconUrl);

	void setCity(const QString& city);
	QString city() const;

	void setState(const QString& state);
	QString state() const;

	void setLatitude(const QString& latitude);
	QString latitude() const;

	void setLongitude(const QString& longitude);
	QString longitude() const;


	void setWeather(const QString& weather);
	QString weather() const;

	void setTemperature(const QString& temperature);
	QString temperature() const;


	void setLastObservation(const QString& lastUpdated);
	QString lastObservation() const;


signals:
	void cityChanged();
	void stateChanged();
	void latitudeChanged();
	void longitudeChanged();
	void coordinatesChanged(QString latitude, QString longitude, QString markerUrl);
	void weatherChanged();
	void weatherIconChanged();
	void temperatureChanged();
	void lastObservationChanged();

private slots:
	void onWeatherIconRequestFinished();

private:
	void setWeatherIconUrl(const QString& iconUrl);

	QVariant weatherIcon()const;
	void downloadWeatherIcon(const QString& iconUrl);

	QNetworkAccessManager* m_networkManager;
	QString m_city;
	QString m_state;
	QString m_latitude;
	QString m_longitude;
	QString m_temperature;
	QString m_lastObservation;
	QString m_weather;
	QString m_weatherIconUrl;
	bb::cascades::Image m_weatherIcon;
};

#endif /* CITY_H_ */
