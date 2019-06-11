/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "addexample.h"

//! [0]
TabDialog::TabDialog(TABLASIMBOLOSV2 &ts, BUFFERV2 &bu, QWidget *parent)
    : QDialog(parent)
{
    tabWidget = new QTabWidget;
    tabWidget->setTabPosition(QTabWidget::TabPosition::North);

    tabWidget->addTab(new TablaSimbolosPreview(ts), tr("TblSymb"));
    tabWidget->addTab(new BufferPreview(bu), tr("Buffer"));
    tabWidget->addTab(new Otros(), tr("Otros"));
//! [0]

//! [1] //! [2]
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
//! [1] //! [3]
                                     | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
//! [2] //! [3]

//! [4]
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
//! [4]

//! [5]
    setWindowTitle(tr("show tables compiler"));
}
//! [5]

//! [6]

TablaSimbolosPreview::TablaSimbolosPreview(TABLASIMBOLOSV2 &ts,QWidget *parent)
    : QWidget(parent)
{
    //here table symbols preview
    model = new QStandardItemModel(this);
    columnView = new QColumnView;
    QStandardItem *name = new QStandardItem("Name");
    QStandardItem *firstName = new QStandardItem("First Name");
    QStandardItem *lastName = new QStandardItem("Last Name");

    name->appendRow(firstName);
    name->appendRow(lastName);
    model->appendRow(name);
    QStandardItem *john = new QStandardItem("John");
    QStandardItem *smith = new QStandardItem("Smith");

    firstName->appendRow(john);
    lastName->appendRow(smith);

    QStandardItem *address = new QStandardItem("Address");
    QStandardItem *street = new QStandardItem("Street");
    QStandardItem *city = new QStandardItem("City");
    QStandardItem *state = new QStandardItem("State");
    QStandardItem *country = new QStandardItem("Country");

    address->appendRow(street);
    address->appendRow(city);
    address->appendRow(state);
    address->appendRow(country);
    model->appendRow(address);

    QStandardItem *ciudad1 = new QStandardItem("New York");
    QStandardItem *ciudad2 = new QStandardItem("Lima");

    city->appendRow(ciudad1);
    city->appendRow(ciudad2);

    columnView->setModel(model);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(columnView);
    setLayout(layout);



}
//! [6]



//! [7]
BufferPreview::BufferPreview(BUFFERV2 &bu, QWidget *parent)
    : QWidget(parent)
{
    //here buffer preview
}
//! [7]

//! [8]
Otros::Otros(QWidget *parent)
    : QWidget(parent)
{
    //here table preview
}
//! [8]
