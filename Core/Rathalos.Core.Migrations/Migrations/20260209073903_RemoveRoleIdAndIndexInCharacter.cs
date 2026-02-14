using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Rathalos.Core.Migrations.Migrations
{
    /// <inheritdoc />
    public partial class RemoveRoleIdAndIndexInCharacter : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "RoleId",
                table: "characters");

            migrationBuilder.DropColumn(
                name: "RoleIndex",
                table: "characters");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<decimal>(
                name: "RoleId",
                table: "characters",
                type: "numeric(20,0)",
                nullable: false,
                defaultValue: 0m);

            migrationBuilder.AddColumn<int>(
                name: "RoleIndex",
                table: "characters",
                type: "integer",
                nullable: false,
                defaultValue: 0);
        }
    }
}
