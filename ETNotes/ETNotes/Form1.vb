Public Class Form1

    Private Sub NewToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NewToolStripMenuItem.Click
        RichTextBox1.Clear()
    End Sub

    Private Sub OpenToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OpenToolStripMenuItem.Click
        Try
            Dim dlg As OpenFileDialog = New OpenFileDialog
            dlg.Title = "Open"
            dlg.Filter = "Rich Text Files (*.rtf) | *.rtf"
            If dlg.ShowDialog() = Windows.Forms.DialogResult.OK Then
                RichTextBox1.LoadFile(dlg.FileName)
            End If
        Catch ex As Exception : End Try
    End Sub

    Private Sub SaveToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveToolStripMenuItem.Click
        Try
            Dim dlg As SaveFileDialog = New SaveFileDialog
            dlg.Title = "Save"
            dlg.Filter = "Rich Text Files (*.rtf) | *.rtf"
            If dlg.ShowDialog() = Windows.Forms.DialogResult.OK Then
                RichTextBox1.SaveFile(dlg.FileName, RichTextBoxStreamType.RichText)
            End If
        Catch ex As Exception : End Try
    End Sub

    Private Sub ExitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem.Click
        End
    End Sub

    Private Sub UndoToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles UndoToolStripMenuItem.Click
        RichTextBox1.Undo()
    End Sub

    Private Sub RedoToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RedoToolStripMenuItem.Click
        RichTextBox1.Redo()
    End Sub

    Private Sub CutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CutToolStripMenuItem.Click
        RichTextBox1.Cut()
    End Sub

    Private Sub CopyToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CopyToolStripMenuItem.Click
        RichTextBox1.Copy()
    End Sub

    Private Sub PasteToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PasteToolStripMenuItem.Click
        RichTextBox1.Paste()
    End Sub

    Private Sub ClearToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ClearToolStripMenuItem.Click
        RichTextBox1.Clear()
    End Sub

    Private Sub SelectAllToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SelectAllToolStripMenuItem.Click
        RichTextBox1.SelectAll()
    End Sub

    Private Sub FontToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles FontToolStripMenuItem.Click
        Try
            Dim dlg As FontDialog = New FontDialog
            dlg.Font = RichTextBox1.Font
            If dlg.ShowDialog() = Windows.Forms.DialogResult.OK Then
                RichTextBox1.Font = dlg.Font
            End If
        Catch ex As Exception

        End Try
    End Sub

    Private Sub ColorToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ColorToolStripMenuItem.Click
        Try
            Dim dlg As ColorDialog = New ColorDialog
            dlg.Color = RichTextBox1.ForeColor
            If dlg.ShowDialog() = Windows.Forms.DialogResult.OK Then
                RichTextBox1.ForeColor = dlg.Color
            End If
        Catch ex As Exception

        End Try
    End Sub

    Private Sub HelpTopicsToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles HelpTopicsToolStripMenuItem.Click
        MessageBox.Show("Not Implemented Yet")
    End Sub

    Private Sub AboutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AboutToolStripMenuItem.Click
        MessageBox.Show("(c) 2023 Erdem Topalsalih")
    End Sub
End Class
