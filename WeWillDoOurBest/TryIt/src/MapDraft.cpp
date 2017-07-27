#include "../headers/MapDraft.h"
#include <QPainter>
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

MapDraft::MapDraft(QWidget *parent): QFrame(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    this -> last_choice = nullptr;
}

void MapDraft::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void MapDraft::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void MapDraft::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void MapDraft::mousePressEvent(QMouseEvent *event)
{
    if(this -> current_choice == MapDraft::NOTYPE){
        this -> handleDragDrop(event);
        return;
    }
    else if(this -> current_choice == MapDraft::DELETE_CELL){
        this -> handleDeleteCell(event);
        return;
    }
    else if(this -> current_choice == MapDraft::CONNECT_CELL){
        this -> handleConnectCell(event);
        return;
    }
    else if(this -> current_choice == MapDraft::DISCONNECT_CELL){
        this -> handleDisconnectCell(event);
        return;
    }
    else{
        this -> handleAddCell(event, (Cell::CellType)current_choice);
    }

}

void MapDraft::handleDragDrop(QMouseEvent *event)
{
    Cell *child = static_cast<Cell*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}

void MapDraft::handleAddCell(QMouseEvent *event, Cell::CellType cellType)
{
    Cell *child = static_cast<Cell*>(childAt(event->pos()));
    if (child)
        return;
    this -> addCell(event->x(), event->y(), cellType);
}

void MapDraft::addCell(int posX, int posY, Cell::CellType cellType)
{
    Cell *cellIcon = new Cell(cellType,this);
    auto it = this->cells.end();
    unsigned long long int newID = 0;
    if(this->cells.begin() != this->cells.end()){
        it--;
        newID = (*it)->getCellID() + 1;
    }
    else{
        newID = 0;
    }
    cellIcon->setCellID(newID);
    cellIcon->setPos(posX - WIDTHCELL/2, posY-HEIGHTCELL/2);
    cellIcon->move(posX - WIDTHCELL/2, posY-HEIGHTCELL/2);
    cellIcon->show();
    cellIcon->setAttribute(Qt::WA_DeleteOnClose);
    this->cells.push_back(cellIcon);
}

void MapDraft::handleDeleteCell(QMouseEvent *event)
{
    Cell *child = static_cast<Cell*>(childAt(event->pos()));
    if(!child)
        return ;
    deleteCell(child);
}

void MapDraft::deleteCell(Cell *child)
{
    auto child_it = std::find(this -> cells.begin(), this -> cells.end(), child);
    if(child_it != this -> cells.end())
    {
        this -> cells.erase(child_it);
        for_each(this -> cells.begin(), this -> cells.end(), [&child](Cell *item){item -> removeAdjacent(child);});
        child -> close();
    }
}

void MapDraft::handleConnectCell(QMouseEvent *event)
{
    Cell *child = static_cast<Cell*>(childAt(event->pos()));
    if(!child)
        return;
    if (this -> last_choice == nullptr){
        this -> last_choice = child;
        this -> last_choice -> highlight();
    }
    else
    {
        //QLine* line = new QLine(this->last_choice->pos(), child->pos());
        //QPainter p(this);
        //p.setRenderHint(QPainter::Antialiasing);
        //p.setPen(QPen(Qt::black, 12, Qt::DotLine, Qt::RoundCap));
        //p.drawLine(*line);
        //p.end();

        //QPaintEngine* u = this->paintEngine();
        //u->drawLines(line, 1);
        //if(std::find_if())                    //Because temprorily we can not draw a line

        this -> last_choice -> addAdjacent(child);
        child -> addAdjacent(this -> last_choice);
        this -> last_choice -> loadImage();
        this -> last_choice = nullptr;
    }
}

void MapDraft::handleDisconnectCell(QMouseEvent *event)
{
    Cell *child = static_cast<Cell*>(childAt(event->pos()));
    if(!child)
        return;
    if (this -> last_choice == nullptr){
        this -> last_choice = child;
        this -> last_choice -> highlight();
    }
    else{
        this -> last_choice -> removeAdjacent(child);
        child -> removeAdjacent(this -> last_choice);
        this -> last_choice -> loadImage();
        this -> last_choice = nullptr;
    }
}

const std::vector<Cell *> &MapDraft::getAllCell()
{
    return this -> cells;
}

void MapDraft::setAllCell(const std::vector<Cell *> &inputList)
{
    this->cells = inputList;
}
